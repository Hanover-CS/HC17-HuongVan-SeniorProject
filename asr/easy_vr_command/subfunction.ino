/*
 * tonePlay function that takes two arguments of int. First one determines the sound, and the second parameter determines frequency of chosen sound.
 * then it will call the bult-in tone with the arguments passed.
 * the sound will last for 1s by calling buil-int delay with approriate value.
 */
void tonePlay(int sound1, int frequency) {
   tone(5, sound1, frequency);
   delay(1000);
}

/*
 * Function action that will determine which group we are at and what commands are spoken. It takes no arguments and will direct through what values group/idx/id (state indicators)
 * are recognized by the speech recognition shield. The action will use switch with group indicator to put the flow in right group. 
 * When the flow are in the approriate group, the action function will call the function inside that group with the idx indicator. 'idx indicator' takes responsible to seperate commands
 * by its corresponding idx's. This will help the function inside each group to know what action to direct Obedient Robot to move. The flows will be demonstrated as following rules:
 * 1. GROUP_0: will call the trigger function with idx
 * 2. GROUP_1: will call the basic function with idx. 
 * 3. GROUP_2: will call the direction function with idx to set the id indicator which will later on will use to determine what function will then be used to direct Obedient. The last 
 *    id will be the stop that will direct the flow back to the list of option (GROUP_4)
 * 4. GROUP_3: will call the numberRecognized function with id set in GROUP_2 and value of idx indicator of the numbers recognized by speech recognition shield. For each case 
 *    of this function, there will be a break that would allow the user to change numeric parameters with the same function. The last case will be the stop which set the group back
 *    to GROUP_2 in order to pick different functions.
 * The function will return nothing.
 */
void action(){
   switch (group){
      case GROUP_0:
//      switch (idx)
//      {
//      case G0_OBEDIENT:
//        // write your action code here
//        // group = GROUP_X; <-- or jump to another group X for composite commands
//        tonePlay(1500, 1000); //backward sound
//        group = GROUP_1;
//        break;
//      }
          trigger(idx);
          break;
      case GROUP_1:
          basic(idx);
          break;
      case GROUP_2:
          pickMovement(idx);
          break;
      case GROUP_3:
          numberRecognized(idx);
          break;
      case GROUP_4:
          basicOrAdvanced(idx);
          break;
  }
}

/*
 * trigger function take no argument and will set the group indicator to GROUP_4, list of option. Also it will call tonePlay(1500, 1000)
 * to announce that it gets the word from user. It only work if idx = G0_OBEDIENT
 */
void trigger(int idx) {
    if (idx == G0_OBEDIENT) {
        tonePlay(1500, 1000);
        group = GROUP_4;
    }
}

/* This is the function that handle the user's choices between basic or advanced commands
 * then it will direct the flow to the corresponding place to tell what Obedient should obey
 * This is only work if we passed the right idx, which is 0 for "basic" and 1 for "advanced"
 * it will set the group to the value corresponding to basic and advanced group of commands.
 */
void basicOrAdvanced(int idx) {
    switch(idx) {
        case G4_BASIC:
            tonePlay(1500, 1000);
            group = GROUP_1;
            break;
        case G4_ADVANCED:
           tonePlay(1000, 1000);
           group = GROUP_2;
           break;
    }
}

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
        case G1_STOP:
            group = GROUP_4;
            break;
    }
}

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
        case G2_STOP:
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
