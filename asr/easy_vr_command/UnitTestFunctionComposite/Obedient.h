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
		void fowardSecond(int second);
		void backwardSecond(int second);
		void stopSecond(int second);

		//Methods without quantity
		void stop();
		int foward();
		int backward();
		int turnBackLeft();
		int turnBackRight();
		int turnLeft();
		void turnRight();
		void circleLeft();
		void circleRight();

	private:
		int _servoLeft, _servoRight;
		Servo left, right;
		int turnDegree(int dir, int degree);
		int move(int dir, int s);
};
#endif
