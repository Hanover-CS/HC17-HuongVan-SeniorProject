#ifndef _FUNCTION_COMPOSITE_H_
#define _FUNCTIONC_COMPOSITE_H_

#include "obedient.h"

/* This is the function that handle the trigger to start the Obedient
 * This is only work if we passed the right idx, which is 0, and not working 
 * at all for other cases
 */
int trigger(int idx);

/* This is the function that handle the user's choices between basic or advanced commands
 * then it will direct the flow to the corresponding place to tell what Obedient should obey
 * This is only work if we passed the right idx, which is 0 for "basic" and 1 for "advanced"
 * it will set the group to the value corresponding to basic and advanced group of commands.
 */
void basicOrAdvanced(int idx);

/* This is the function that handle the basic movements of the Obedient
*  This is only work if we passed the approriate idx's, which is 0-6, and not working
*  at all for other cases
*/
int basic(int idx);

/* This is the function that direct to appropriate functions with numbers
*  This is only work if we passed the approriate idx's, which is 0-3, and not working
*  at all for other cases
*/
int pickMovement(int idx);

/* This is the function that passed argument to forward function that will tell Obedient 
*  to move forward for that seconds of time
*  This is only work if we passed the approriate idx's, which is 0-19, and not working
*  at all for other cases
*/
int foward_with_time();

/* This is the function that passed argument to backward function that will tell Obedient
*  to move forward for that seconds of time
*  This is only work if we passed the approriate idx's, which is 0-19, and not working
*  at all for other cases
*/
int backward_with_time();

/* This is the function that passed argument to turnLeft function that will tell Obedient
*  to move forward for that seconds of time
*  This is only work if we passed the approriate idx's, which is 0-19, and not working
*  at all for other cases
*/
int turnLeft_with_degree();

/* This is the function that passed argument to turnRight function that will tell Obedient
*  to move forward for that seconds of time
*  This is only work if we passed the approriate idx's, which is 0-19, and not working
*  at all for other cases
*/
int turnRight_with_degree();

/* This is the function that passed argument to action that where the Obedient will take the input from users
*  With the help of switch statement based on group, it will direct the flow to the right place
*  at which, the appropriate function will get call and carry out the action.
*  This is will take two arguments group, and idx. The group will direct the flow to where the function lies, 
*  then the function get call with the idx. 
*/
int action(int group, int idx);

/* mainMenu function
 *  This is the function that handle the user's choices between basic or advanced commands
 * then it will direct the flow to the corresponding place to tell what Obedient should obey
 * This is only work if we passed the right idx, which is 0 for "basic" and 1 for "advanced"
 * it will set the group to the value corresponding to basic and advanced group of commands.
 * @param {integer} idx - the idx stores value that easyvr passes when it recognize a word from user
 */
int mainMenu(int idx) {
    switch(idx) {
        case G4_BASIC:
            tonePlay(1500, 1000);
            group = GROUP_1;
            g = GROUP_1;
            break;
        case G4_ADVANCED:
            tonePlay(1000, 1000);
            group = GROUP_2;
            break;
        case G4_SENSOR:
            tonePlay(1200, 1000);
            group = GROUP_1;
            g = GROUP_5;
            break;
        case G4_LIST:
            tonePlay(1200, 1000);
            group = GROUP_1;
            g = GROUP_6;
            break;
    }

    return group;
}

/*
 * sensorOrBasicOrList function
 * Since the three module `sensor`, `basic` and `list` will use the same command library since they will direct the Obedient with the same movement.
 * I decided to use the three module with the same command group id, that is the reason we need this function to actually determine what module we really want
 * to call at the time.
 * @param {integer} choice - that will tell which module to be loaded.
 */
int sensorOrBasicOrList(int choice)

/* This is the function that determine what unit we will use for function in advanced group
*     0 - all functions work with unit of seconds
*     1 - all functions work with unit of metric, in this case is inch
*  @param {integer} idx - the idx of the command that the shield recognized.
*  The function will return nothing, but set `unit` variable to corresponding unit.
*/
int pickUnit(int idx);

#endif
