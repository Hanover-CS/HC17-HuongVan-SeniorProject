/**************************************End of module introduction ******************************************************/
/* This is the function that determine what unit we will use for function in advanced group
*     0 - all functions work with unit of seconds
*     1 - all functions work with unit of metric, in this case is inch
*  @param {integer} idx - the idx of the command that the shield recognized.
*  The function will return nothing, but set `unit` variable to corresponding unit.
*/
void pickUnit(int idx) {
    tonePlay(1600, 1000);    
    unit = idx;  
}

