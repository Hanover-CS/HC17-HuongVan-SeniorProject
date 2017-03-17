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
enum Groups
{
  GROUP_0 = 0,
  GROUP_1 = 1,
  GROUP_2 = 2,
  GROUP_4 = 4,
};

enum Group0 
{
  G0_OBEDIENT = 0,
};

enum Group1 
{
  G1_FOWARD = 0,
  G1_BACKWARD = 1,
  G1_LEFTTURN = 2,
  G1_RIGHTTURN = 3,
  G1_TURNBACKLEFT = 4,
  G1_TURNBACKRIGHT = 5,
  G1_STOP = 6,
};

enum Group4
{
  G4_BASIC = 0,
  G4_ADVANCED = 1,
};

// Declares variable id for the direction function here
// variable group to keep track of the current group within action function
// variable idx to keep track of the commands in each group within subfunctions of action function
int8_t group, idx, id;
Obedient obedient(10, 11);

void setup()
{
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

void loop()
{
  if (easyvr.getID() < EasyVR::EASYVR3)
    easyvr.setPinOutput(EasyVR::IO1, HIGH); // LED on (listening)

  Serial.print("Say a command in Group ");
  Serial.println(group);
  easyvr.recognizeCommand(group);

  do
  {
    // can do some processing while waiting for a spoken command
  }
  while (!easyvr.hasFinished());
  
  if (easyvr.getID() < EasyVR::EASYVR3)
    easyvr.setPinOutput(EasyVR::IO1, LOW); // LED off

  idx = easyvr.getWord();
  if (idx >= 0)
  {
    // built-in trigger (ROBOT)
    // group = GROUP_X; <-- jump to another group X
    return;
  }
  idx = easyvr.getCommand();
  if (idx >= 0)
  {
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
  else // errors or timeout or not recognized words
  {
    if (easyvr.isTimeout())
      Serial.println("Timed out, try again...");
    int16_t err = easyvr.getError();
    if (err >= 0)
    {
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
void action()
{
    switch (group)
    {
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
        group = GROUP_1;
        break;
    case G4_ADVANCED:
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
        break;
    case G1_BACKWARD:
        obedient.backward();
        break;
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

