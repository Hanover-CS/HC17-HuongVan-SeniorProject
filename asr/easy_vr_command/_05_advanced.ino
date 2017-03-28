/*
 * Advance module
 * This module hosts advanced group functions. It will help the user to pick what movement they want obedient to perform and
 * also how they want it to perform them in number (degree/ distance/ time)
 * This module will be loaded with action module
 */
/**************************************End of module introduction ******************************************************/
/* This is the function that direct to appropriate functions with numbers
*  This is only work if we passed the approriate idx's, which is 0-4, and not working
*  at all for other cases
*  The idx is ranging from 0-4 and each idx takes one responsibility as following:
*     0 - set id indicator to G2_FOWARD
*     1 - set id indicator to G2_BACKWARD
*     2 - set id indicator to G2_LEFTTURN
*     3 - set id indicator to G2_RIGHTTURN
*     4 - set group indicator to GROUP_4 to exit the advanced commands and enter list of options.
*  pickMovement function return nothing, except set id indicator (id that will later on use in GROUP_3 as one of its functions' parameter to direct 
*  the Obedient).
*/
void pickMovement(int idx) {
    group = GROUP_3;
    switch(idx) {
        case G2_FOWARD:
            tonePlay(1000, 1000);
            id = G2_FOWARD;
            break;
        case G2_BACKWARD:
            tonePlay(1200, 1000);
            id = G2_BACKWARD;
            break;
        case G2_RIGHTTURN:
            tonePlay(1400, 1000);
            id = G2_RIGHTTURN;
            break;
        case G2_LEFTTURN:
            tonePlay(1600, 1000);
            id = G2_LEFTTURN;
            break;
        case G2_PICKUNIT:
            tonePlay(1600, 1000);
            group = GROUP_7;
            break;
        case G2_MAINMENU:
            tonePlay(1800, 1000);
            group = GROUP_4;
            break;
    }
}

/* This is the function that recognizes a number said to the Obedient. This recognized numbers will be used as a parameter in numberRecognized along
 * with the id indicator that we already set up in group 2 and will call the approriate function that determine the movement of Obedient.
 * after it perform the function, it will then set the group indicator back to group2 for the next performing function.
 */
void numberRecognized(int idx) {
    int val = idx + 1;    
    
    switch(id) {
        case G2_FOWARD:
            fowardWithUnit(val, unit);
            break;
        case G2_BACKWARD:
            backwardWithUnit(val, unit);
            break;
        case G2_LEFTTURN:
            obedient.turnDegree(1, val * 50);
            obedient.stop();
            break;
        case G2_RIGHTTURN:
            obedient.turnDegree(0, val * 50);
            obedient.stop();
            break;
    }
    group = GROUP_2;
}

/* This is the function that will help numberRecognized function to determine what unit it should call with the foward and backward function.
 * @param {integer} val - the value that spoken to numberRecognized function and will be the value that will call with fowardSecond or fowardDistance
 * @param {integer} unit - the value that determines what unit we are going to use
 * The function will return nothing but will call an approriate function that will directs Obedient.
 */
void fowardWithUnit(int val, int unit) {
    if (unit == UNIT_SECOND) {
        obedient.fowardSecond(val);        
    } else {
        obedient.fowardDistance(val * 10); // since val will be from 1-5 but we want 1 represent for 10 inch.   
    }
    obedient.stop();
}

/* This is the function that will help numberRecognized function to determine what unit it should call with the backward function.
 * @param {integer} val - the value that spoken to numberRecognized function and will be the value that will call with backward or backwardDistance
 * @param {integer} unit - the value that determines what unit we are going to use
 * The function will return nothing but will call an approriate function that will directs Obedient.
 */
void backwardWithUnit(int val, int unit) {
    if (unit == UNIT_SECOND) {
        obedient.backwardSecond(val);        
    } else {
        obedient.backwardDistance(val * 10); // since val will be from 1-5 but we want 1 represent for 10 inch.   
    }
    obedient.stop();
}
