/* 
	Obedient source file - Library for directing Obedient robot with movements
	Created by Hoang N.H. Van, November 14, 2016
	Released into public domain
*/

#include "Arduino.h"
#include "Obedient.h"



//Constructor with pin
Obedient::Obedient(int servoLeft, int servoRight)
{
	_servoLeft = servoLeft;
	_servoRight = servoRight;
}

/**************************Public Method*************************************/
void Obedient::attachServo() {
	left.attach(_servoLeft);
	right.attach(_servoRight);
}

//Foward with Second
void Obedient::fowardSecond(int second)
{
 	move(1, second);
 	stopSecond(1);
}

//Move backward with Second
void Obedient::backwardSecond(int second)
{
  	move(0, second);
  	stopSecond(1);	
}

//Stop with Second
void Obedient::stopSecond(int second)
{
  	left.writeMicroseconds(1500);
  	right.writeMicroseconds(1500);
  	delay(second * 1000);
}

//Default stop
void Obedient::stop()
{
	stopSecond(10);
}

//Default Foward
void Obedient::foward()
{
  fowardSecond(5);
  stopSecond(1);
}

//Default Backward
void Obedient::backward()
{
  backwardSecond(5);
  stopSecond(1);
}

//Turn back left
void Obedient::turnBackLeft()
{
	turnDegree(1, 180);
	stopSecond(1);
}

//Turn back right
void Obedient::turnBackRight()
{
	turnDegree(0, 180);
	stopSecond(1);
}

//Turn Left
void Obedient::turnLeft()
{
	turnDegree(1, 90);
	stopSecond(1);
}

//Turn right
void Obedient::turnRight()
{
	turnDegree(0, 90);
	stopSecond(1);
}

//TUrn 1 left circle around 
void Obedient::circleLeft()
{
	turnDegree(1, 360);
	stopSecond(1);
}

//TUrn 1 right circle around 
void Obedient::circleRight()
{
	turnDegree(0, 360);
	stopSecond(1);
}
/**************************END*******************************************/

/**************************Private Method************************************/
void Obedient::turnDegree(int dir, int degree)
{
	degree = (int)(degree / 0.95) * 8;
	if (dir == 1) {
		left.writeMicroseconds(1300);
 		right.writeMicroseconds(1300);
 		delay(degree);
	} else {
		left.writeMicroseconds(1700);
 		right.writeMicroseconds(1700);
 		delay(degree);
	}
}

void Obedient::move(int dir, int s)
{
	if (dir == 1) {
		left.writeMicroseconds(1600);
  		right.writeMicroseconds(1400);
  		delay(s * 1000);
	} else {
		left.writeMicroseconds(1400);
  		right.writeMicroseconds(1600);
  		delay(s * 1000);
	}
}

/**************************END***********************************************/
