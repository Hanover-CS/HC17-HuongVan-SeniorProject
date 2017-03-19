#include "Arduino.h"
#include <Obedient.h>

#if !defined(SERIAL_PORT_MONITOR)
  #error "Arduino version not supported. Please update your IDE to the latest version."
#endif

#if defined(SERIAL_PORT_USBVIRTUAL)
  // Shield Jumper on HW (for Leonardo and Due)
  #define port SERIAL_PORT_HARDWARE
  #define pcSerial SERIAL_PORT_USBVIRTUAL
#else
  // Shield Jumper on SW (using pins 12/13 or 8/9 as RX/TX)
  #include "SoftwareSerial.h"
  SoftwareSerial port(12, 13);
  #define pcSerial SERIAL_PORT_MONITOR
#endif

#include "EasyVR.h"

EasyVR easyvr(port);

//Groups and Commands
enum Groups {
  GROUP_0 = 0, //trigger
  GROUP_1 = 1, //basic
  GROUP_2 = 2, //direction
  GROUP_3 = 3, //group of numbers
  GROUP_4 = 4, //basicOrAdvanced
};

//Trigger command idx's
enum Group0 {
  G0_OBEDIENT = 0,
};

//Basic command idx's
enum Group1 {
  G1_FOWARD = 0,
  G1_BACKWARD = 1,
  G1_LEFTTURN = 2,
  G1_RIGHTTURN = 3,
  G1_TURNBACKLEFT = 4,
  G1_TURNBACKRIGHT = 5,
  G1_STOP = 6,
};

// pick a movement
enum Group2 {
  G2_FOWARD = 0,
  G2_BACKWARD = 1,
  G2_LEFTTURN = 2,
  G2_RIGHTTURN = 3,
  G2_STOP = 4,
};

// pick a number as a parameter
enum Group3 {
   G3_1 = 0;
   G3_2 = 1;
   G3_3 = 2;
   G3_4 = 3;
   G3_5 = 4;
   G3_6 = 5;
   G3_7 = 6;
   G3_8 = 7;
   G3_9 = 8;
   G3_10 = 9;
   G3_11 = 10;
   G3_12 = 11;
   G3_13 = 12;
   G3_14 = 13;
   G3_15 = 14;
   G3_16 = 15;
   G3_17 = 16;
   G3_18 = 17;
   G3_19 = 18;
   G3_20 = 19;
};

//Basic or Advanced?
enum Group4 {
  G4_BASIC = 0,
  G4_ADVANCED = 1,
};

// variable group to keep track of the current group within action function
// variable idx to keep track of the commands in each group within subfunctions of action function
// Declares variable id for the direction function here
int8_t group, idx, id;

// Declares obedient
Obedient obedient(10, 11);

void setup() {
  obedient.attachServo();
  // setup PC serial port
  pcSerial.begin(9600);

  // bridge mode?
  int mode = easyvr.bridgeRequested(pcSerial);
  switch (mode)
  {
  case EasyVR::BRIDGE_NONE:
    // setup EasyVR serial port
    port.begin(9600);
    // run normally
    pcSerial.println(F("---"));
    pcSerial.println(F("Bridge not started!"));
    break;
    
  case EasyVR::BRIDGE_NORMAL:
    // setup EasyVR serial port (low speed)
    port.begin(9600);
    // soft-connect the two serial ports (PC and EasyVR)
    easyvr.bridgeLoop(pcSerial);
    // resume normally if aborted
    pcSerial.println(F("---"));
    pcSerial.println(F("Bridge connection aborted!"));
    break;
    
  case EasyVR::BRIDGE_BOOT:
    // setup EasyVR serial port (high speed)
    port.begin(115200);
    // soft-connect the two serial ports (PC and EasyVR)
    easyvr.bridgeLoop(pcSerial);
    // resume normally if aborted
    pcSerial.println(F("---"));
    pcSerial.println(F("Bridge connection aborted!"));
    break;
  }

  while (!easyvr.detect())
  {
    Serial.println("EasyVR not detected!");
    delay(1000);
  }

  easyvr.setPinOutput(EasyVR::IO1, LOW);
  Serial.println("EasyVR detected!");
  easyvr.setTimeout(5);
  easyvr.setLanguage(0);

  group = EasyVR::TRIGGER; //<-- start group (customize)
}

void action();

void loop() {
  if (easyvr.getID() < EasyVR::EASYVR3)
    easyvr.setPinOutput(EasyVR::IO1, HIGH); // LED on (listening)

  Serial.print("Say a command in Group ");
  Serial.println(group);
  easyvr.recognizeCommand(group);

  do {
    // can do some processing while waiting for a spoken command
  }
  while (!easyvr.hasFinished());
  
  if (easyvr.getID() < EasyVR::EASYVR3)
    easyvr.setPinOutput(EasyVR::IO1, LOW); // LED off

  idx = easyvr.getWord();
  if (idx >= 0) {
    // built-in trigger (ROBOT)
    // group = GROUP_X; <-- jump to another group X
    return;
  }
  idx = easyvr.getCommand();
  if (idx >= 0) {
    // print debug message
    uint8_t train = 0;
    char name[32];
    Serial.print("Command: ");
    Serial.print(idx);
    if (easyvr.dumpCommand(group, idx, name, train))
    {
      Serial.print(" = ");
      Serial.println(name);
    }
    else
      Serial.println();
	// beep
    easyvr.playSound(0, EasyVR::VOL_FULL);
    // perform some action
    action();
  }
  // errors or timeout or not recognized words
   else {
      if (easyvr.isTimeout())
         Serial.println("Timed out, try again...");
      int16_t err = easyvr.getError();
      if (err >= 0) {
         Serial.print("Error ");
         Serial.println(err, HEX);
   }
  }
}

/*
 * tonePlay function that takes two arguments of int. First one determines the sound, and the second parameter determines frequency of chosen sound.
 * then it will call the bult-in tone with the arguments passed.
 * the sound will last for 1s by calling buil-int delay with approriate value.
 */
void tonePlay(int sound1, int frequency) {
   tone(5, sound1, frequency);
   delay(1000);
}

/*
 * Function action that will determine which group we are at and what commands are spoken. It takes no arguments and will direct through what values group/idx/id (state indicators)
 * are recognized by the speech recognition shield. The action will use switch with group indicator to put the flow in right group. 
 * When the flow are in the approriate group, the action function will call the function inside that group with the idx indicator. 'idx indicator' takes responsible to seperate commands
 * by its corresponding idx's. This will help the function inside each group to know what action to direct Obedient Robot to move. The flows will be demonstrated as following rules:
 * 1. GROUP_0: will call the trigger function with idx
 * 2. GROUP_1: will call the basic function with idx. 
 * 3. GROUP_2: will call the direction function with idx to set the id indicator which will later on will use to determine what function will then be used to direct Obedient. The last 
 *    id will be the stop that will direct the flow back to the list of option (GROUP_4)
 * 4. GROUP_3: will call the numberRecognized function with id set in GROUP_2 and value of idx indicator of the numbers recognized by speech recognition shield. For each case 
 *    of this function, there will be a break that would allow the user to change numeric parameters with the same function. The last case will be the stop which set the group back
 *    to GROUP_2 in order to pick different functions.
 * The function will return nothing.
 */
void action(){
   switch (group){
      case GROUP_0:
//      switch (idx)
//      {
//      case G0_OBEDIENT:
//        // write your action code here
//        // group = GROUP_X; <-- or jump to another group X for composite commands
//        tonePlay(1500, 1000); //backward sound
//        group = GROUP_1;
//        break;
//      }
          trigger(idx);
          break;
      case GROUP_1:
          basic(idx);
          break;
      case GROUP_2:
          pickMovement(idx);
      case GROUP_4:
          basicOrAdvanced(idx);
          break;
  }
}

/*
 * trigger function take no argument and will set the group indicator to GROUP_4, list of option. Also it will call tonePlay(1500, 1000)
 * to announce that it gets the word from user. It only work if idx = G0_OBEDIENT
 */
void trigger(int idx) {
   if (idx == G0_OBEDIENT) {
        tonePlay(1500, 1000);
        group = GROUP_4;
   }
}

/* This is the function that handle the user's choices between basic or advanced commands
 * then it will direct the flow to the corresponding place to tell what Obedient should obey
 * This is only work if we passed the right idx, which is 0 for "basic" and 1 for "advanced"
 * it will set the group to the value corresponding to basic and advanced group of commands.
 */
void basicOrAdvanced(int idx) {
   switch(idx) {
     case G4_BASIC:
         tonePlay(1500, 1000);
         group = GROUP_1;
         break;
     case G4_ADVANCED:
         tonePlay(1000, 1000);
         group = GROUP_2;
         break;
   }
}

/* The basic function that will take one parameter of idx indicator and based on the value of idx to determine which function will be called inside itself.
 * The basic function also call tonePlay(1000, 1000) inside it to annouce that it gets the word from the user.
 * The idx will then determine which movement the Obedient will carry out
 *     if idx = G1_FOWARD, then call foward function
 *     if idx = G1_BACKWARD, then call backward function
 *     if idx = G1_LEFTTURN, then call turnLeft function
 *     if idx = G1_RIGHTTURN, then call turnRight function
 *     if idx = G1_TURNBACKLEFT, then call turnBackLeft function
 *     if idx = G1_TURNBACKRIGHT, then call turnBackRight function
 *     if idx = G1_STOP, then call stop function to move back to list of option (GROUP_4)
 * We will use switch structure to recognize each case based on the value of idx.
 * The function will return nothing.     
 */
void basic(int idx) {
   tonePlay(1000, 1000);
   switch(idx) {
     case G1_FOWARD:
         obedient.foward();
//         break;
     case G1_BACKWARD:
         obedient.backward();
//         break;
     case G1_LEFTTURN:
         obedient.turnLeft();
         break;
     case G1_RIGHTTURN:
         obedient.turnRight();
         break;
     case G1_TURNBACKLEFT:
         obedient.turnBackLeft();
         break;
     case G1_TURNBACKRIGHT:
         obedient.turnBackRight();
         break;
     case G1_STOP:
         group = GROUP_4;
         break;
   }
}

/* This is the function that direct to appropriate functions with numbers
*  This is only work if we passed the approriate idx's, which is 0-4, and not working
*  at all for other cases
*  The idx is ranging from 0-4 and each idx takes one responsibility as following:
*     0 - set id indicator to G2_FOWARD
*     1 - set id indicator to G2_BACKWARD
*     2 - set id indicator to G2_LEFTTURN
*     3 - set id indicator to G2_RIGHTTURN
*     4 - set group indicator to GROUP_4 to exit the advanced commands and enter list of options.
*  pickMovement function return nothing, except set id indicator (id that will later on use in GROUP_3 as one of its functions' parameter to direct 
*  the Obedient).
*/
void pickMovement(int idx) {
   group = GROUP_3;
   switch(idx) {
       case G2_FOWARD:
           tonePlay(1000, 1000);
           id = G2_FOWARD;
           break;
       case G2_BACKWARD:
           tonePlay(1200, 1000);
           id = G2_BACKWARD;
           break;
       case G2_RIGHTTURN:
           tonePlay(1400, 1000);
           id = G2_RIGHTTURN;
           break;
       case G2_LEFTTURN:
           tonePlay(1600, 1000);
           id = G2_LEFTTURN;
           break;
       case G2_STOP:
           tonePlay(1800, 1000);
           group = GROUP_4;
           break;
   }
}

/* This is the function that recognizes a number said to the Obedient. This recognized numbers will be used as a parameter in numberRecognized along
 * with the id indicator that we already set up in group 2 and will call the approriate function that determine the movement of Obedient.
*/
void numberRecognized(int idx) {
   switch(id) {
      case G2_FOWARD:
         obedient.fowardSecond(idx);
         break;
      case G2_BACKWARD:
         obedient.backwardSecond(idx);
      case G2_LEFTTURN:
         obedient.turnDegree(1, idx * 10);
      case G2_RIGHTTURN:
         obedient.turnDegree(0, idx * 10);
   }
}
