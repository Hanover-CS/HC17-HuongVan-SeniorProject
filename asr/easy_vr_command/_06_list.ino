/* This is the module that direct Obedient with mutiple provided commands.
*  The Obedient starts to obey the actions when the users say 'go'. The module will take care of two things: 
*  1. Keep storing a command into a list until the user say `go`
*  2. Following each command by the order it was placed in the list.
*  This will use commands in basic group to populate the list of actions.
*/
/**************************End of module introduction ******************************************************/
#include <QueueArray.h>
QueueArray<int> listAction;

/* 
*  The Obedient starts to obey the actions when the users say 'go'. The module will take care of two things: 
*  1. Keep storing a command into a list until the user say `go`
*  2. Following each command by the order it was placed in the list.
*  This will use commands in Advance group to populate the list of action.
*/
void listCommand(int idx) {
    switch(idx) {
        case LIST_FOWARD:
            tonePlay(1000, 1000);
            listAction.push(idx);
            break;
        case LIST_BACKWARD:
            tonePlay(1000, 1000);
            listAction.push(idx);
            break;
        case LIST_LEFTTURN:
            tonePlay(1000, 1000);
            listAction.push(idx);
            break;
        case LIST_RIGHTTURN:
            tonePlay(1000, 1000);
            listAction.push(idx);
            break;
        case LIST_BACKLEFT:
            tonePlay(1000, 1000);
            listAction.push(idx);
            break;
        case LIST_TURNBACKRIGHT:
            tonePlay(1000, 1000);
            listAction.push(idx);
            break; 
        case LIST_GO:
            tonePlay(1000, 1000);
            doList();
            break;
        case LIST_MAINMENU:
            tonePlay(1500, 1000);
            group = GROUP_4;
    }      
}
/*
 * doList function
 * It will keep doing the action stored in listAction until the list is empty
 * The function has no parameters and return nothing.
 * The function will pop the item in listAction and pass that value to doAction
 */
void doList() {
    int act;
    
    while(!listAction.isEmpty()) {
        act = listAction.pop();
        doAction(act);        
    }
}

/*
 * doAction
 * This function will take one argument, and based on that act id, it will ask the Obedient to perform the action
 * @param {integer} act - action id:
 * LIST_FOWARD :  to go foward
 * LIST_BACKWARD :  to go backward
 * LIST_LEFTTURN :  to go turn left
 * LIST_RIGHTTURN: to turn right
 * LIST_BACKLEFT :  to go BACK LEFT
 * LIST_BACKRIGHT: to turn back from the right
 * return nothing
 */
void doAction(int act) {
    switch(act) {
        case LIST_FOWARD:
            obedient.foward();
            break;
        case LIST_BACKWARD:
            obedient.backward();
            break;
        case LIST_LEFTTURN:
            obedient.turnLeft();
            break;
        case LIST_RIGHTTURN:
            obedient.turnRight();
            break;
        case LIST_BACKLEFT:
            obedient.turnBackLeft();
            break;
        case LIST_TURNBACKRIGHT:
            obedient.turnBackRight();
            break;   
    }
}


