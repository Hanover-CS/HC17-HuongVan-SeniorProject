#ifndef _FUNCTION_COMPOSITE_H_
#define _FUNCTIONC_COMPOSITE_H_

/* This is the function that handle the trigger to start the Obedient
 * This is only work if we passed the right idx, which is 0, and not working 
 * at all for other cases
 */
int trigger(int idx);

/* This is the function that handle the basic movements of the Obedient
*  This is only work if we passed the approriate idx's, which is 0-6, and not working
*  at all for other cases
*/
int basic(int idx);

/* This is the function that direct to appropriate functions with numbers
*  This is only work if we passed the approriate idx's, which is 0-3, and not working
*  at all for other cases
*/
int direction(int idx);

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

#endif
