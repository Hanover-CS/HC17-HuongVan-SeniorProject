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
int const dirFoward = 1;
int const dirBackward = 0;
int const dirLeft = 1;
int const dirRight = 0;

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
    move(dirFoward, second);
}
/*
 * Direct Obedient to go foward with certain distance.
 *
 * @param {integer} distance - distance travel in inches
 * this has to be a multiple of 10 inches.
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::fowardDistance(int distance) {
    int timeTraveled;
    
    // It takes 1.62 second at default speed to travel 10 inches
    timeTraveled = distance * 1620 / 10;
    fowardNonStop();
    delay(timeTraveled);
}
/*
 * Direct Obedient to go backward with certain distance.
 *        
 * @param {integer} distance - distance travel in inches
 * this has to be a multiple of 10 inches.
 * @memberof Obedient
 * @static
 * @instance        
 */
void Obedient::backwardDistance(int distance) {
    int timeTraveled;
    
    // It takes 1.62 second at default speed to travel 10 inches
    timeTraveled = distance * 1620 / 10;
    backwardNonstop();
    delay(timeTraveled);
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
    move(dirBackward, second);
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
    // delay(second * 1000);
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
    turnDegree(dirLeft, 180);
    stopSecond(1);
}

/*
 * Direct the Obedient to turn back (180 degree) from the right.
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::turnBackRight() {
    turnDegree(dirRight, 180);
    stopSecond(1);
}

/*
 * Direct the Obedient to turn left 90 degree
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::turnLeft() {
    turnDegree(dirLeft, 90);
    stopSecond(1);
}

/*
 * Direct the Obedient to turn right 90 degree
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::turnRight() {
    turnDegree(dirRight, 90);
    stopSecond(1);
}

/*
 * Direct the Obedient to make a full circle from the left.
 * @memberof Obedient
 * @static
 * @instance
 */
void Obedient::circleLeft() {
    turnDegree(dirLeft, 360);
    stopSecond(1);
}

/*
 * Direct the Obedient to make a full circle from the right.
 * @memberof Obedient
 * @static
 * @instance
 */ 
void Obedient::circleRight() {
    turnDegree(dirRight, 360);
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
    if (dir == dirLeft) {
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
    if (dir == dirFoward) {
        left.writeMicroseconds(pulseLeft);
        right.writeMicroseconds(pulseRight);
        delay(s * 1000);
    } else {
        // To move backward, keep the values of pulseRight and pulseLeft unchanged
        // however, we assign them to opposite variable.
        left.writeMicroseconds(pulseRight);
        right.writeMicroseconds(pulseLeft);
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

/*
 * Reset back to default values for all private variables
 *
 * `currentState` is set to DEFAULT_STATE
 * `pulseLeft` is set to pulseLeftDefault
 * `pulseRight` is set to pulseRightDefault
 * @example obedient.setCurrentState(1)
 * @memberof Obedient
 * @instance
 */
void Obedient::reset() {
    currentState = currentSateDefault;
    pulseRight = pulseRightDefault;
    pulseLeft = pulseLeftDefault;
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

/*
 * Speed the Obedient up
 * The function takes no arguments and return nothing
 * @postcondition: everytime the speed up function get called
 * the pulseLeft increases by 50 and pulseRight reduces by 50
 * @condition will be used so that the pulseLeft is never fall off 1700
 * and pulseRight never goes below 1300
 * @example obedient.speedUp().
 * @memberof Obedient
 * @static
 * @instance
 * this function will be used to implement speedUp/slowDown function later
 */
void Obedient::speedUp() {
    pulseLeft = pulseLeft + 50;
    pulseRight = pulseRight - 50;
    if (pulseRight < 1300) {
        pulseRight = 1300;
    }
    if (pulseLeft > 1700) {
        pulseLeft = 1700;
    }
}

/*
 * Slow the Obedient down
 * The function takes no arguments and return nothing
 * @postcondition: everytime the speed up function get called
 * the pulseLeft decreases by 50 and pulseRight increases by 50
 * @condition will be used so that the pulseLeft is never fall off 1500
 * and pulseRight never goes above 1500
 * @example obedient.slowDown().
 * @memberof Obedient
 * @static
 * @instance
 * this function will be used to implement speedUp/slowDown function later
 */
void Obedient::slowDown() {
    pulseLeft = pulseLeft - 50;
    pulseRight = pulseRight + 50;
    if (pulseRight > 1500) {
        pulseRight = 1500;
    }
    if (pulseLeft < 1500) {
        pulseLeft = 1500;
    }
}
/**************************END***********************************************/
