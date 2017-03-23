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
            obedient.fowardSecond(val);
            obedient.stop();
            break;
        case G2_BACKWARD:
            obedient.backwardSecond(val);
            obedient.stop();
            break;
        case G2_LEFTTURN:
            obedient.turnDegree(1, val * 10);
            obedient.stop();
            break;
        case G2_RIGHTTURN:
            obedient.turnDegree(0, val * 10);
            obedient.stop();
            break;
    }
    group = GROUP_2;
}
