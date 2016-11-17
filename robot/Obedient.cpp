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
void turnDegree(int degree)
{
	servoLeft.writeMicroseconds(1300);
 	servoRight.writeMicroseconds(1300);
 	int turnD = (int) degree * 1500 / 180;
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

//Turn back 
void Obedient::turnBack()
{

}

//Turn Left
void Obedient::turnLeft()
{

}

//Turn right
void Obedient::turnRight()
{

}

//TUrn 1 circle around
void Obedient::circle()
{

}
/**************************END*******************************************/
