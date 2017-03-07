#include <iostream>
#include "function_composite.h"
using namespace std;

//group
extern int GROUP_0;
extern int GROUP_1;

//command group0 idx;
extern int G0_OBEDIENT;

//command group1 idx
extern int G1_FOWARD;
extern int G1_BACKWARD;
extern int G1_LEFTTURN;
extern int G1_RIGHTTURN;
extern int G1_TURNBACKLEFT;
extern int G1_TURNBACKRIGHT;
extern int G1_STOP;

//command group2 idx
extern int G2_FOWARD;
extern int G2_BACKWARD;
extern int G2_LEFTTURN;
extern int G2_RIGHTTURN;

extern int group = -1;

void test_trigger() {
	int result;
	
	result = trigger(1);
	assert(result == -1);
	result = trigger(0);
	assert(result == 0);
	group = -1;
}

void test_basic() {
	int result;
	
	result = basic(-1);
	assert(result == -1);
	result = basic(7);
	assert(result == -1);
	for (int i = 0; i < 7; i++) {
		result = basic(i);
		assert(result == i);
	}
}

void test_numeric() {
	int result;

	//Test with outside legal choice
	result = direction(-2);
	assert(result == -2);

	//Test with forward function
	result = direction(G2_FOWARD);
	assert(result == G2_FOWARD);

	//Test with backward function
	result = direction(G2_BACKWARD);
	assert(result == G2_BACKWARD);

	//Test with turnleft function
	result = direction(G2_LEFTTURN);
	assert(result == G2_LEFTTURN);

	//Test with turnright function
	result = direction(G2_RIGHTTURN);
	assert(result == G2_RIGHTTURN);
}
void test_numeric_forward() {
	foward_with_time();
}

int main() {
	test_trigger();
	test_basic();
	test_numeric();
	return 0;
}