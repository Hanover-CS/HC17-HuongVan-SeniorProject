/*
 * Test speed for servo
 * 
 * This file is meant to test the speed of the servo corresponding to each pulse passed to servo.
 * Since each servo has its own speed corresponding to each pulse. I suggest that you should download
 * this file and record the speed of your own servo for more accuracy calculation in both distance and speed
 * Author: Hoang Van
 * requires: Servo.h
 */
 #include <Servo.h>

 // Declare servos that will represent for two wheels of the robot
 Servo servoLeft, servoRight;

/*
 * Setup function - set up all the variable and declaration that will be use along
 * the way when the file compiled and run.
 * Putting all the variable, or system needed to setup here
 * Take no argument and return nothing
 */
void setup() {
    // put your setup code here, to run once:
    // Make some sounds here to make sure a system works fine.
    tone(5, 1000, 1000);
    delay(1000);

    // Print out testing information to the serial
    Serial.begin(9600);

    // Attach servos to right port
    servoLeft.attach(10);
    servoRight.attach(11);

}

/*
 * Loop function - will run everything in here and then start another loop and keep running until
 * the program is ended.
 * Putting thing that you want to run over and over again in here.
 * Takes no arguments and return nothing
 */
void loop() {
    for (int pulse = 1375; pulse <= 1625; pulse += 25) {
        // Display pulse value for recording
        Serial.print("pulse = ");
        Serial.println(pulse);

        // Waiting for the start announcement
        Serial.println("Press a key and click");
        Serial.println("Send to start servo...");

        // Will do nothing if the user has not press any key
        while(Serial.available() == 0) {
            Serial.read();  
        }

        // When the user press the key, start testing each of the servo one at a time
        Serial.println("Running...");
        servoLeft.writeMicroseconds(pulse);
        //servoRight.writeMicrosecond(pulse);
        delay(6000)

        // stop the servo after the test.
        servoLeft.writeMicroseconds(1500);
        //servoRight.writeMicroseconds(1500);
    }
  

}
