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
 * 
 */
void loop() {
  
  

}
