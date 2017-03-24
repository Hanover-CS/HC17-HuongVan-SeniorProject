/*
 *  Obedient.h - Library for directing Obedient robot with movements
 *  This is the Obedient class definition file that will serve as function declarations,
 *  It will have class constructor - to create instance of the Obedient class
 *  Setters - functions that set private variable of each instance of Obedient class.
 *  Getters - functions that get private variable of each instance of Obedient class
 *  Movements - functions that will help Obedient to direct its movements. Those functions are built
 *              using already existed function from Arduino library.
 *  This will be downloaded to Arduino libraries folder so that the sketch can be compiled and worked.
 *  Created by Hoang N.H. Van, November 14, 2016
 *  Released into public domain.
*/

#ifndef Obedient_h
#define Obedient_h

#include "Arduino.h"
#include "Servo.h"

class Obedient {
    public:
        //Constructor
        Obedient(int servoLeft, int servoRight);

        //Setters
        void setCurrentState(int current);

        //Getters
        int getCurrentState();

        //Initial Servos
        void attachServo();

        //Methods with quantity
        void fowardSecond(int second);
        void backwardSecond(int second);
        void stopSecond(int second);

        //Methods without quantity
        void stop();
        void foward();
        void backward();
        void turnBackLeft();
        void turnBackRight();
        void turnLeft();
        void turnRight();
        void circleLeft();
        void circleRight();
        void turnDegree(int dir, int degree);

    private:
        int _servoLeft, _servoRight, currentState;
        Servo left, right;
        void move(int dir, int s);
};
#endif
