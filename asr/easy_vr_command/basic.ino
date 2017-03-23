
/**************************************End of module introduction ******************************************************/
/* The basic function that will take one parameter of idx indicator and based on the value of idx to determine which function will be called inside itself.
 * The basic function also call tonePlay(1000, 1000) inside it to annouce that it gets the word from the user.
 * The idx will then determine which movement the Obedient will carry out
 *     if idx = G1_FOWARD, then call foward function
 *     if idx = G1_BACKWARD, then call backward function
 *     if idx = G1_LEFTTURN, then call turnLeft function
 *     if idx = G1_RIGHTTURN, then call turnRight function
 *     if idx = G1_TURNBACKLEFT, then call turnBackLeft function
 *     if idx = G1_TURNBACKRIGHT, then call turnBackRight function
 *     if idx = G1_STOP, then call stop function to move back to list of option (GROUP_4)
 * We will use switch structure to recognize each case based on the value of idx.
 * The function will return nothing.     
 */
void basic(int idx) {
    tonePlay(1000, 1000);
    switch(idx) {
        case G1_FOWARD:
            obedient.foward();
            break;
        case G1_BACKWARD:
            obedient.backward();
            break;
        case G1_LEFTTURN:
            obedient.turnLeft();
            break;
        case G1_RIGHTTURN:
            obedient.turnRight();
            break;
        case G1_BACKLEFT:
            obedient.turnBackLeft();
            break;
        case G1_TURNBACKRIGHT:
            obedient.turnBackRight();
            break;
        case G1_MAINMENU:
            group = GROUP_4;
            break;
    }
}
