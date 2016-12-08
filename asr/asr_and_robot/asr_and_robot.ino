#include "Arduino.h"
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
#include <Servo.h>


EasyVR easyvr(port);
Servo servoLeft;
Servo servoRight;

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
  G1_TURNLEFT = 2,
  G1_TURNRIGHT = 3,
  G1_AROUNDFROMLEFT = 4,
  G1_RIGHTTURNAROUND = 5,
  G1_STOP = 6,
};


int8_t group, idx;

void setup()
{
  // setup PC serial port
  pcSerial.begin(9600);

  servoLeft.attach(10);
  servoRight.attach(11);

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
    group = GROUP_1;
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

void action()
{
    switch (group)
    {
    case GROUP_0:
      switch (idx)
      {
      case G0_OBEDIENT:
        // write your action code here
        // group = GROUP_X; <-- or jump to another group X for composite commands
        group = GROUP_1;
        break;
      }
      break;
    case GROUP_1:
      switch (idx)
      {
      case G1_FOWARD:
        // write foward action code here
        tone(5, 4500, 1000); //foward sound
        delay(1000);
        servoLeft.writeMicroseconds(1600);
        servoRight.writeMicroseconds(1400);
        delay(3000);
        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);
        break;
      case G1_BACKWARD:
        // write backward action code here
        tone(5, 1000, 1000); //backward sound
        delay(1000);
        servoLeft.writeMicroseconds(1400);
        servoRight.writeMicroseconds(1600);
        delay(3000);
        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);
        break;
      case G1_TURNRIGHT:
        // write your action code here
        tone(5, 2000, 1000); //right turn sound
        delay(1000);
        servoLeft.writeMicroseconds(1700);
        servoRight.writeMicroseconds(1700);
        delay(750);
        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);
        break;
      case G1_TURNLEFT:
        // write your action code here
        tone(5, 2000, 1000); //right turn sound
        delay(1000);
        servoLeft.writeMicroseconds(1300);
        servoRight.writeMicroseconds(1300);
        delay(750);
        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);
        break;
      case G1_AROUNDFROMLEFT:
        // write around left action code here
        tone(5, 3000, 1000); //right turn sound
        delay(1000);
        servoLeft.writeMicroseconds(1300);
        servoRight.writeMicroseconds(1300);
        delay(1500);
        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);
        break;
      case G1_RIGHTTURNAROUND:
        // write around right action code here
        tone(5, 2000, 1000); //right turn sound
        delay(1000);
        servoLeft.writeMicroseconds(1700);
        servoRight.writeMicroseconds(1700);
        delay(1500);
        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);
        break;
      case G1_STOP:
        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);
        break;
      }
      break;
    }
}
