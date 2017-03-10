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
int Obedient::fowardSecond(int second)
{
 	return move(1, second);
}

//Move backward with Second
int Obedient::backwardSecond(int second)
{
  	return move(0, second);	
}

//Stop with Second
void Obedient::stopSecond(int second)
{
  	left.writeMicroseconds(1500);
  	right.writeMicroseconds(1500);
  	delay(second * 1000);
}

//Default stop
int Obedient::stop()
{
	return 600;
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
int Obedient::turnBackLeft()
{
    return 400;
}

//Turn back right
int Obedient::turnBackRight()
{
	return 500;
}

//Turn Left
int Obedient::turnLeft()
{
	return 200;
}

//Turn right
int Obedient::turnRight()
{
	return 300;
}

//TUrn 1 left circle around 
int Obedient::circleLeft()
{
	return turnDegree(1, 360);
}

//TUrn 1 right circle around 
int Obedient::circleRight()
{
	return turnDegree(0, 360);
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
