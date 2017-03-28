/*
 * This is the action module
 * The module that will hold the action function - function that will direct Obedient based on what word easyvr recognizes.
 * The module will be loaded in easy_vr_command module
 */
/**************************************End of module introduction ******************************************************/
// Declare the subgroup indicator for group 3 and group 4.
int g;
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
          trigger(idx);
          break;
      case GROUP_1:
          sensorOrBasicOrList(g);
          break;
      case GROUP_2:
          pickMovement(idx);
          break;
      case GROUP_3:
          numberRecognized(idx);
          break;
      case GROUP_4:
          mainMenu(idx);
          break;
      case GROUP_7:
          pickUnit(idx);
          break;
  }
}

/*
 * trigger function trigger and wake the Obedient up and ready for the commands. 
 * @param {integer} idx - the idx that eavyvr will pass to whenever it can recognize a word from user
 * The function will set the group indicator to GROUP_4, list of option. 
 * Also it will call tonePlay(1500, 1000)to announce that it gets the word from user. It only work if idx = G0_OBEDIENT
 */
void trigger(int idx) {
    if (idx == G0_OBEDIENT) {
        tonePlay(1500, 1000);
        group = GROUP_4;
    }
}

/* mainMenu function
 *  This is the function that handle the user's choices between basic or advanced commands
 * then it will direct the flow to the corresponding place to tell what Obedient should obey
 * This is only work if we passed the right idx, which is 0 for "basic" and 1 for "advanced"
 * it will set the group to the value corresponding to basic and advanced group of commands.
 * @param {integer} idx - the idx stores value that easyvr passes when it recognize a word from user
 */
void mainMenu(int idx) {
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
}

/*
 * sensorOrBasicOrList function
 * Since the three module `sensor`, `basic` and `list` will use the same command library since they will direct the Obedient with the same movement.
 * I decided to use the three module with the same command group id, that is the reason we need this function to actually determine what module we really want
 * to call at the time.
 * @param {integer} choice - that will tell which module to be loaded.
 */
void sensorOrBasicOrList(int choice) {
    switch(choice) {
        case GROUP_1:
            basic(idx);
            break;
        case GROUP_5:
            sensor(idx);
            break;
        case GROUP_6:
            listCommand(idx); 
            break;   
    }
}

