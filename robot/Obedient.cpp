/* 
	Obedient source file - Library for directing Obedient robot with movements
	Created by Hoang N.H. Van, November 14, 2016
	Released into public domain
*/

#include "Arduino.h"
#include "Obedient.h"

// Declare constant value here
int const pulseLeftDefault = 1600;
int const pulseRightDefault = 1400;
int const pulseStop = 1500;
int const currentSateDefault = -1;
int const foward = 1;
int const backward = 0;
int const left = 1;
int const right = 0;

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
 * @post-condition: the currentState is set to default value of -1 and pulseLeft = 1600, pulseRight = 1400
 */
Obedient::Obedient(int servoLeft, int servoRight) {
    _servoLeft = servoLeft;
    _servoRight = servoRight;
    currentState = currentSateDefault;
    pulseRight = pulseRightDefault;
    pulseLeft = pulseLeftDefault;
}

/**************************Settup Servo Method*************************************/
/*
 * Attach servo port to real robot wheels that can control by Arduino board
 * 
 * @example obedient.attachServo()
 * @memberof Obedient
 * @instance
 */
void Obedient::attachServo() {
    left.attach(_servoLeft);
    right.attach(_servoRight);
}

/**************************Public Method*************************************/
/**********************Movement Functions with Parameters**********************/
/*
 * Direct Obedient to go foward with certain time.
 *
 * @param {integer} second - time that Obedient will move
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::fowardSecond(int second) {
    move(1, second);
    // stopSecond(1);
}

/*
 * Direct Obedient to go backward with certain time.
 *
 * @param {integer} second - time that Obedient will move
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::backwardSecond(int second) {
    move(0, second);
    // stopSecond(1);	
}

/*
 * Stop the Obedient.
 *
 * @param {integer} second - time that Obedient will stop
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::stopSecond(int second) {
    left.writeMicroseconds(pulseStop);
    right.writeMicroseconds(pulseStop);
    delay(second * 1000);
}

/**********************Default Movement Functions**********************/
/*
 * Stop the Obedient in default period of time (1 seconds)
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::stop() {
    stopSecond(1);
}

/*
 * Direct the Obedient to go foward in default period of time (5 seconds)
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::foward() {
    fowardSecond(5);
    stopSecond(1);
}

/*
 * Direct the Obedient to go backward in default period of time (5 seconds)
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::backward() {
    backwardSecond(5);
    stopSecond(1);
}

/*
 * Direct the Obedient to turn back (180 degree) from the left.
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::turnBackLeft() {
    turnDegree(1, 180);
    stopSecond(1);
}

/*
 * Direct the Obedient to turn back (180 degree) from the right.
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::turnBackRight() {
    turnDegree(0, 180);
    stopSecond(1);
}

/*
 * Direct the Obedient to turn left 90 degree
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::turnLeft() {
    turnDegree(1, 90);
    stopSecond(1);
}

/*
 * Direct the Obedient to turn right 90 degree
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::turnRight() {
    turnDegree(0, 90);
    stopSecond(1);
}

/*
 * Direct the Obedient to make a full circle from the left.
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::circleLeft() {
    turnDegree(1, 360);
    stopSecond(1);
}

/*
 * Direct the Obedient to make a full circle from the right.
 * @memberof Obedient
 * @static
 * @instance
 */ 
void Obedient::circleRight() {
    turnDegree(0, 360);
    stopSecond(1);
}

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
void Obedient::turnDegree(int dir, int degree) {
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
void Obedient::move(int dir, int s) {
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
void Obedient::setCurrentState(int current) {
    currentState = current;
}

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
int Obedient::getCurrentState() {
    return currentState;
}

/**************************END***********************************************/
