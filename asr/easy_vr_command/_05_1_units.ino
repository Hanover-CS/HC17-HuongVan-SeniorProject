/*
 * unit module
 * This module hosts the pickUnit function. That will help to pick the right unit in advanced command. Since the users can decide what
 * units of measurement they want to use with their commands.
 * This module will be loaded with advanced module.
 */
/**************************************End of module introduction ******************************************************/
/* This is the function that determine what unit we will use for function in advanced group
*     0 - all functions work with unit of seconds
*     1 - all functions work with unit of metric, in this case is inch
*  @param {integer} idx - the idx of the command that the shield recognized.
*  The function will return nothing, but set `unit` variable to corresponding unit.
*/
void pickUnit(int idx) {
    // Make a sound so that users know shield recognize their words
    tonePlay(1600, 1000);  
    // Set up the unit to the right unit  
    unit = idx;
    // Get back to the advanced group so that we can call function with the right unit.
    group = GROUP_2; 
}

