#include "function_composite.h"

//group
extern const int GROUP_0 = 0;
extern const int GROUP_1 = 1;

//command group0 idx
extern const int G0_OBEDIENT = 0;

//command group1 idx
extern const int G1_FOWARD = 0;
extern const int G1_BACKWARD = 1;
extern const int G1_LEFTTURN = 2;
extern const int G1_RIGHTTURN = 3;
extern const int G1_TURNBACKLEFT = 4;
extern const int G1_TURNBACKRIGHT = 5;
extern const int G1_STOP = 6;

//command group2 idx
extern const int G2_FOWARD = 0;
extern const int G2_BACKWARD = 1;
extern const int G2_LEFTTURN = 2;
extern const int G2_RIGHTTURN = 3;

//command idx with forward (group3)
extern const int G3_1 = 0;
extern const int G3_2 = 1;
extern const int G3_3 = 2;
extern const int G3_4 = 3;
extern const int G3_5 = 4;
extern const int G3_6 = 5;
extern const int G3_7 = 6;
extern const int G3_8 = 7;
extern const int G3_9 = 8;
extern const int G3_10 = 9;
extern const int G3_11 = 10;
extern const int G3_12 = 11;
extern const int G3_13 = 12;
extern const int G3_14 = 13;
extern const int G3_15 = 14;
extern const int G3_16 = 15;
extern const int G3_17 = 16;
extern const int G3_18 = 17;
extern const int G3_19 = 18;
extern const int G3_20 = 19;

extern int group = -1;



/* This is the function that handle the trigger to start the Obedient
* This is only work if we passed the right idx, which is 0, and not working
* at all for other cases
*/
int trigger(int idx) {
	switch(idx) {
	    case G0_OBEDIENT:
		    group = GROUP_1;
	}

	return group;
}

/* This is the function that handle the basic movements of the Obedient
*  This is only work if we passed the approriate idx's, which is 0-6, and not working
*  at all for other cases
*/
int basic(int idx) {
	switch(idx) {
	    case G1_FOWARD:
			return G1_FOWARD;
		case G1_BACKWARD:
			return G1_BACKWARD;
		case G1_LEFTTURN:
			return G1_LEFTTURN;
		case G1_RIGHTTURN:
			return G1_RIGHTTURN;
		case G1_TURNBACKLEFT:
			return G1_TURNBACKLEFT;
		case G1_TURNBACKRIGHT:
			return G1_TURNBACKRIGHT;
	}
	return -1;
}

/* This is the function that direct to appropriate functions with numbers
*  This is only work if we passed the approriate idx's, which is 0-3, and not working
*  at all for other cases
*/
int direction(int idx) {
	switch(idx) {
	    case G2_FOWARD:
			return G2_FOWARD;
		case G2_BACKWARD:
			return G2_BACKWARD;
		case G2_RIGHTTURN:
			return G2_RIGHTTURN;
		case G2_LEFTTURN:
			return G2_LEFTTURN;
	}
	
	return -1;
}