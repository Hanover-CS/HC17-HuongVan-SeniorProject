/*
 * Easy_vr_commands module.
 * 
 * This module is respnsible for declaring and setting up Obedient variable and the easyvr system.
 * This will include function that will print out current state of the easyvr to serial for testing.
 * 
 * requires: _02_groups_commands_id.ino, _03_action.ino, _04_basic.ino, _05_1_units.ino, _05_advanced.ino, _06_list.ino, _07_sensor.ino, sounding.ino
 * This is the main file that will compiled and will call other modules in the interface between Robot and Easyvr shield
 */
/*
 * Include general Arduino libraries, Obedient library.
 */
#include "Arduino.h"
#include <Obedient.h>

/*
 * Code that check if Arduino Software is updated to date or not. We will need the Arduino Software at least 1.8.2. But the newer the Arduino Software the more
 * compatible the code will run.
 */
#if !defined(SERIAL_PORT_MONITOR)
  #error "Arduino version not supported. Please update your IDE to the latest version."
#endif

// Define serial port for printing information that Easyvr get from users to Serial. This is for testing purpose
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

// Include built-in EasyVR library, which is in the Arduino Libraries Folder.
#include "EasyVR.h"
// Declare easyvr
EasyVR easyvr(port);
// variable group to keep track of the current group within action function
// variable idx to keep track of the commands in each group within subfunctions of action function
// Declares variable id for the direction function here
// Declares unit
int8_t group, idx, id, unit;

// Declares obedient
Obedient obedient(10, 11);

/*
 * setup function.
 * This function will be responsible for set up all the variable needed in the interface.
 * Set up the obedient and attach servo to the approriate wheels
 * Set up and run bridge code, which is needed to run EasyVR with Robot board. 
 * Set up Serial port for printing information to serial. This is used for testing what EasyVR recognizes.
 * And set up the initial value for `group` indicator. `group` indicator shows what group we are currently at and the intial value for it will be EASYVR::TRIGGER
 * This function takes no argument and return nothing
 */
void setup() {
    // Attach indicating LED to pin
    // This LED will help us to determine when to say a command.
    pinMode(7, OUTPUT);
    //Attach servo left and right to the left and right wheels of the Robot.
    obedient.attachServo();
    // Default unit to use is second.
    unit = 0;
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

    // Waiting for EasyVR being recognized. If there is no EasyVR recognize, there will be some error with the bridge set up 
    // Print out announcement to users so that they will know that EasyVR is not working properly.
    while (!easyvr.detect())
    {
        Serial.println("EasyVR not detected!");
        delay(1000);
    }

    // While easyvr is detected. Announce it to users.
    easyvr.setPinOutput(EasyVR::IO1, LOW);
    Serial.println("EasyVR detected!");
    easyvr.setTimeout(5);
    // Set default language to English. You can also set different language. Please refer to EasyVR documentation for more information. 
    // The link to it will be found on my Github page for the Obedient project.
    easyvr.setLanguage(0);
    // Set default initial group.
    group = EasyVR::TRIGGER; //<-- start group (customize)
}

// Call the action function one to wake the Obedient up at this point when the user trigger it.
void action();

/*
 * loop function
 * This function will take no argument and return nothing
 * The function will be used like a while loop and will keep running over and over again until the Robot is stopped.
 * This function will keep waiting for the next command that EasyVR can recognize from users and will direct the Obedient based on what they understand.
 * If the easyvr cannot recognize the command, it will print out that error on the Serial that we already set it up in the `setup` function 
 * We will then call the action() on what easyvr recognize. The action function will be loaded to this modul through _03_action.ino
 */
void loop() {
    // Flashing the LED on robot to announce that it is waiting for a commad
    flashLED();
    // Flashing the LED on easyvr shield to annouce that easyvr is waiting for a command
    if (easyvr.getID() < EasyVR::EASYVR3)
        easyvr.setPinOutput(EasyVR::IO1, HIGH); // LED on (listening)
    Serial.print("Say a command in Group ");
    Serial.println(group);
    easyvr.recognizeCommand(group);

    // You can add some thing you want the 
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
        if (easyvr.dumpCommand(group, idx, name, train)) {
            Serial.print(" = ");
            Serial.println(name);
        } else
            Serial.println();
            // perform some action based on what easyvr can recognize
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
 * flashLED function
 * This function will flash the LED to announce the user that the obedient is waiting for the command.
 * return nothing and take no arguments
 */
void flashLED() {
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(7, LOW);
    delay(500); 
}

