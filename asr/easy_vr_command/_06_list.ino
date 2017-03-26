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
            group = GROUP_4;
    }      
}
void doList() {
    int act;
    
    while(!listAction.isEmpty()) {
        act = listAction.pop();
        doAction(act);        
    }
}

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


