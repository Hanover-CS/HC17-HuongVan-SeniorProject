/*
	Obedient.h - Library for directing Obedient robot with movements
	Created by Hoang N.H. Van, November 14, 2016
	Released into public domain.
*/

#ifndef OBEDIENT_H
#define OBEDIENT_H

#include "Arduino.h"
#include <Servo.h>

class Obedient
{
	public:
		Obedient(int servoLeft, int servoRight);

		//Methods with quantity
		void fowardSecond(int second);
		void backwardSecond(int second);

		//Methods without quantity
		void foward();
		void backward();
		void turnBackLeft();
		void turnBackRight();
		void turnLeft();
		void turnRight();
		void circleLeft();
		void circleRight();

	private:
		int _servoLeft, _servoRight;
		Servo left, right;
		void turnDegree(int dir, int degree);
		void move(int dir, int s);

};
#endif
