#include <Servo.h>
  Servo servoLeft;
  Servo servoRight;
void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(13);
  servoRight.attach(12);

}

void loop() {
  //backward for 3 seconds
  tone(5, 1000, 1000); //backward sound
  delay(1000);
  servoLeft.writeMicroseconds(1400);
  servoRight.writeMicroseconds(1600);
  delay(3000);
  delay(1000);
  //stop for 1 seconds
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1000);
  //foward for 3 seconds
  tone(5, 4500, 1000); //foward sound
  delay(1000);
  servoLeft.writeMicroseconds(1600);
  servoRight.writeMicroseconds(1400);
  delay(3000);
  delay(1000);
  //stop for 1 seconds
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1000);
  //180 left turn
  tone(5, 3000, 1000); //right turn sound
  delay(1000);
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(1500);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1000);
  //180 right turn
  tone(5, 2000, 1000); //right turn sound
  delay(1000);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(1500);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1000);
  //90 right turn
  tone(5, 2000, 1000); //right turn sound
  delay(1000);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(750);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1000);
  //90 left turn
  tone(5, 2000, 1000); //right turn sound
  delay(1000);
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(750);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1000);
  // 360 left turn
  tone(5, 2000, 1000); //right turn sound
  delay(1000);
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(3000);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1000);
  //360 right turn
  tone(5, 2000, 1000); //right turn sound
  delay(1000);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(3000);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1000);
}
