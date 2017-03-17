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
  GROUP_0  = 0,
  GROUP_1  = 1,
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
  else // errors or timeout
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
void tonePlay(int sound1, int frequency) {
  tone(5, sound1, frequency);
  delay(1000);
}

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
    }
}

void trigger(int idx) {
  switch(idx) {
    case G0_OBEDIENT:
       tonePlay(1500, 1000);
       group = GROUP_1;
       break;
  }
}

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
        group = GROUP_0;
        break;
  }
}

