#include <iostream>
#include "function_composite.h"
using namespace std;

//group
extern int GROUP_0;
extern int GROUP_1;

//command idx
extern int G0_OBEDIENT;
extern int G1_FOWARD;
extern int G1_BACKWARD;
extern int G1_LEFTTURN;
extern int G1_RIGHTTURN;
extern int G1_TURNBACKLEFT;
extern int G1_TURNBACKRIGHT;
extern int G1_STOP;
extern int group = -1;

void test_trigger() {
	int result = trigger(1);
	assert(result == -1);
	result = trigger(0);
	assert(result == 0);
	group = -1;
}

int main() {
	test_trigger();
	return 0;
}