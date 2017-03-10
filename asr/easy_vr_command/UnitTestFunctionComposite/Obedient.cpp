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
int Obedient::foward()
{
  return 0;
}

//Default Backward
int Obedient::backward()
{
  return 100;
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
int Obedient::turnDegree(int dir, int degree)
{
	if (dir == 1) {
		return 2*100+degree;
	} 

	return 100+degree;
}

int Obedient::move(int dir, int s)
{
	return dir * 100 + s;
}

/**************************END***********************************************/
