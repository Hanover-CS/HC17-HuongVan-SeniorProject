/* 
	Obedient source file - Library for directing Obedient robot with movements
	Created by Hoang N.H. Van, November 14, 2016
	Released into public domain
*/

#include "Arduino.h"
#include <Servo.h>
#include "Morse.h"

//Constructor with pin
Obedient::Obedient(int servoLeft, int servoRight)
{
	_servoLeft = servoLeft;
	_servoRight = servoRight;
	left.attach(_servoLeft);
	right.attach(_servoRight);
}

/**************************Private Method************************************/
void turnDegree(int dir, int degree)
{
	if (dir == 1) {
		servoLeft.writeMicroseconds(1300);
 		servoRight.writeMicroseconds(1300);
	} else {
		servoLeft.writeMicroseconds(1700);
 		servoRight.writeMicroseconds(1700);
	}
 	int turnD = degree * 1500 / 180;
 	delay(turnD);
}

void move(int dir, int s)
{

}

/**************************END***********************************************/

/**************************Public Method*************************************/
//Foward with Second
void Obedient::fowardSecond(int second)
{
 	left.writeMicroseconds(1600);
  	right.writeMicroseconds(1400);
  	delay(second * 1000);
}

//Move backward with Second
void Obedient::backwardSecond(int second)
{
  	left.writeMicroseconds(1400);
  right.writeMicroseconds(1600);
  delay(second * 1000);
}

//Default Foward
void Obedient::foward()
{
  fowardSecond(5);
}

//Default Backward
void Obedient::foward()
{
  backwardSecond(5);
}

//Turn back left
void Obedient::turnBackLeft()
{
	turnDegree(1, 180);
}

//Turn back right
void Obedient::turnBackRight()
{
	turnDegree(0, 180);
}

//Turn Left
void Obedient::turnLeft()
{
	turnDegree(1, 90);
}

//Turn right
void Obedient::turnRight()
{
	turnDegree(0, 90);
}

//TUrn 1 left circle around 
void Obedient::circleLeft()
{
	turnDegree(1, 360);
}

//TUrn 1 right circle around 
void Obedient::circleRight()
{
	turnDegree(0, 360);
}
/**************************END*******************************************/
