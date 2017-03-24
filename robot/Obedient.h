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
 *  
 *  requires: Arduino, Servo
 */

// Define Obedient_h if it has not existed yet.
#ifndef Obedient_h
#define Obedient_h

/* Include general Arduino into the header file so that we can be able to use 
 * alreadily bult-in general functions from Arduino. 
 * 
 * Also included Servo library so that we can control the robot wheels
 * These two libraries are built-in libraries that come which the Arduino Software originally without any further installation
 */
#include "Arduino.h"
#include "Servo.h"

class Obedient {
    public:
        /*
         * Create a new `Obedient`
         *
         * @param {integer} servoLeft - the port that will be assigned to the _servoLeft, left wheel of robot
         * @param {integer} servoRight - the port that will be assigned to the _servoRight, right wheel of robot
         * @return nothing, however, it will need to set the `currentState` to -1 to start with the default Obedient
         * @example Obedient obedient(11, 12)
         * @memberof Obedient
         * @static
         * @public 
         */
        Obedient(int servoLeft, int servoRight);

        /************Setters**********************/
        /*
         * Set value for `currentState`
         *
         * `currentState` is the state of the obedient as follow:
         * 0, for FOWARD
         * 1, for BACKWARD
         * 2, for STOP
         * -1, for DEFAULT_STATE
         * @param {integer} current - the value that will be assigned to `currentState`
         * @example obedient.setCurrentState(1)
         * @memberof Obedient
         * @instance
         */
        void setCurrentState(int current);

        /************Getters**********************/
        /*
         * Get value for `currentState`
         *
         * `currentState` is the state of the obedient as follow:
         * 0, for FOWARD
         * 1, for BACKWARD
         * 2, for STOP
         * -1, for DEFAULT_STATE
         * @param {integer} current - the value that will be assigned to `currentState`
         * @return {integer} A current state of the obedient
         * @example obedient.setCurrentState(1)
         * @memberof Obedient
         * @instance
         */
        int getCurrentState();

        /*
         * Attach servo port to real robot wheels that can control by Arduino board
         * 
         * @example obedient.attachServo()
         * @memberof Obedient
         * @instance
         */
        void attachServo();

        /**********************Movement Functions with Parameters**********************/
        /*
         * Direct Obedient to go foward with certain time.
         *
         * @param {integer} second - time that Obedient will move
         * @memberof Obedient
         * @static
         * @instance
         */
        void fowardSecond(int second);
        /*
         * Direct Obedient to go backward with certain time.
         *
         * @param {integer} second - time that Obedient will move
         * @memberof Obedient
         * @static
         * @instance
         */
        void backwardSecond(int second);
        /*
         * Stop the Obedient.
         *
         * @param {integer} second - time that Obedient will stop
         * @memberof Obedient
         * @static
         * @instance
         */
        void stopSecond(int second);

        /**********************Default Movement Functions**********************/
        /*
         * Stop the Obedient in default period of time (1 seconds)
         * @memberof Obedient
         * @static
         * @instance
         */
        void stop();
        /*
         * Direct the Obedient to go foward in default period of time (5 seconds)
         * @memberof Obedient
         * @static
         * @instance
         */
        void foward();
        /*
         * Direct the Obedient to go backward in default period of time (5 seconds)
         * @memberof Obedient
         * @static
         * @instance
         */
        void backward();
        /*
         * Direct the Obedient to turn back (180 degree) from the left.
         * @memberof Obedient
         * @static
         * @instance
         */
        void turnBackLeft();
        /*
         * Direct the Obedient to turn back (180 degree) from the right.
         * @memberof Obedient
         * @static
         * @instance
         */
        void turnBackRight();
        /*
         * Direct the Obedient to turn left 90 degree
         * @memberof Obedient
         * @static
         * @instance
         */
        void turnLeft();
        /*
         * Direct the Obedient to turn right 90 degree
         * @memberof Obedient
         * @static
         * @instance
         */
        void turnRight();
        /*
         * Direct the Obedient to make a full circle from the left.
         * @memberof Obedient
         * @static
         * @instance
         */
        void circleLeft();
        /*
         * Direct the Obedient to make a full circle from the right.
         * @memberof Obedient
         * @static
         * @instance
         */
        void circleRight();
        /*
         * Direct the Obedient to make a turn.
         * @param {integer} dir - to tell which direction the Obedient should turn:
         *                        0 for left
         *                        1 for right
         * @param {integer} degree - how big the turn is
         * @example obedient.turnDegree(0, 120) stands for turn left with the angle of 120.
         * @memberof Obedient
         * @static
         * @instance
         * This function will be used to implement turning functions later
         */
        void turnDegree(int dir, int degree);
        /*
         * Direct the Obedient to move straight.
         * @param {integer} dir - to tell which direction the Obedient should move:
         *                        0 for foward
         *                        1 for backward
         * @param {integer} s - how long in second the Obedient should move.
         * @example obedient.move(0, 10) stands for foward for 10 seconds.
         * @memberof Obedient
         * @static
         * @instance
         * this function will be used to implement backward/foward function later
         */
        void move(int dir, int s);

    private:
        int _servoLeft, _servoRight, currentState;
        Servo left, right;
};
#endif
