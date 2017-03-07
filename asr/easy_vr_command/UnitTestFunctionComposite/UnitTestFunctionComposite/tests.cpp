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

//command idx with forward (group3)
extern int G3_1;
extern int G3_2;
extern int G3_3;
extern int G3_4;
extern int G3_5;
extern int G3_6;
extern int G3_7;
extern int G3_8;
extern int G3_9;
extern int G3_10;
extern int G3_11;
extern int G3_12;
extern int G3_13;
extern int G3_14;
extern int G3_15;
extern int G3_16;
extern int G3_17;
extern int G3_18;
extern int G3_19;
extern int G3_20;

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

/* This is a cheat code for function with number:
*  foward will range 0-19 for the time corresponding of group3 0-19
*  backward will range 100-119 for the time corresponding group3 0-19 
*  turnLeft will range 200-219 for the angle corresponding group3 0-19
*  turnRight will range 300-319 for the angle corresponding group3 0-19
*/
void test_numeric_foward() {
	for (int i = 0; i < 20; i++) {
		assert(foward_with_time(i) == i);
	}
}

void test_numeric_backward() {
	for (int i = 0; i < 20; i++) {
		assert(foward_with_time(i) == 100 + i);
	}
}

void test_numeric_turnLeft() {
	for (int i = 0; i < 20; i++) {
		assert(turnLeft_with_degree(i) == 200 + i);
	}
}

int main() {
	test_trigger();
	test_basic();
	test_numeric();
	test_numeric_foward();
	test_numeric_backward();
	test_numeric_turnLeft();
	return 0;
}