/*
	Obedient.h - Library for directing Obedient robot with movements
	Created by Hoang N.H. Van, November 14, 2016
	Released into public domain.
*/

#ifndef Obedient_h
#define Obedient_h

#include "Arduino.h"
#include "Servo.h"

class Obedient
{
	public:
		//Constructor
		Obedient(int servoLeft, int servoRight);

		//Initial Servos
		void attachServo();

		//Methods with quantity
		int fowardSecond(int second);
		int backwardSecond(int second);
		void stopSecond(int second);

		//Methods without quantity
		int stop();
		int foward();
		int backward();
		int turnBackLeft();
		int turnBackRight();
		int turnLeft();
		int turnRight();
		int circleLeft();
		int circleRight();

	private:
		int _servoLeft, _servoRight;
		Servo left, right;
		int turnDegree(int dir, int degree);
		int move(int dir, int s);
};
#endif
