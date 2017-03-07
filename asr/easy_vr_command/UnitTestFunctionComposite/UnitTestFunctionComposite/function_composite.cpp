#include "function_composite.h"

//group
extern const int GROUP_0 = 0;
extern const int GROUP_1 = 1;

//command idx
extern const int G0_OBEDIENT = 0;
extern const int G1_FOWARD = 0;
extern const int G1_BACKWARD = 1;
extern const int G1_LEFTTURN = 2;
extern const int G1_RIGHTTURN = 3;
extern const int G1_TURNBACKLEFT = 4;
extern const int G1_TURNBACKRIGHT = 5;
extern const int G1_STOP = 6;
extern int group = -1;

int trigger(int idx) {
	switch (idx) {
	    case G0_OBEDIENT:
		    group = GROUP_1;
	}

	return group;
}