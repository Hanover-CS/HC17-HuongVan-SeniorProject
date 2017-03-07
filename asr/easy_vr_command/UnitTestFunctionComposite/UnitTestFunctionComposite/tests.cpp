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

void test_basic() {
	int result = basic(-1);
	assert(result == -1);
	result = basic(7);
	assert(result == -1);
	for (int i = 0; i < 7; i++) {
		result = basic(i);
		assert(result == i);
	}
}

int main() {
	test_trigger();
	test_basic();
	return 0;
}