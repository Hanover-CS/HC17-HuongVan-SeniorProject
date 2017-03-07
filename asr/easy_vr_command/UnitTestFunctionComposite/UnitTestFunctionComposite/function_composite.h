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

#endif
