#include <iostream>
#include "function_composite.h"
#include "obedient.h"
using namespace std;

//group
extern int GROUP_0;
extern int GROUP_1;
extern int GROUP_2;
extern int GROUP_3;
extern int GROUP_4;

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

//command group4 idx
extern int G4_BASIC;
extern int G4_ADVANCED;

void test_trigger() {
	int result;
	
	result = trigger(1);
	assert(result == -1);
	result = trigger(0);
	assert(result == 4);
	group = -1; //set back to the default group when no group is assigned yet.
}

void test_basicOrAdvanced() {
	result = basicOrAdvanced(0);
	assert(result == 1);
	result = basicOrAdvanced(1);
	assert(result == 2);
	group = -1; //set back to the default group when no group is assigned yet.
}

/*foward will return 0
* backward will return 100
* turnLeft will return 200
* turnRight will return 300
* turnBackLeft will return 400
* turnBackRight will return 500
* stop will return 600
*/
void test_basic() {
	int result;
	
	result = basic(-1);
	assert(result == -1);
	result = basic(7);
	assert(result == -1);
	for (int i = 0; i < 7; i++) {
		result = basic(i);
		assert(result == i*100);
	}
}

void test_numeric() {
	int result;

	//Test with outside legal choice
	result = pickMovement(-2);
	assert(result == -2);

	//Test with forward function
	result = pickMovement(G2_FOWARD);
	assert(result == G2_FOWARD);

	//Test with backward function
	result = pickMovement(G2_BACKWARD);
	assert(result == G2_BACKWARD);

	//Test with turnleft function
	result = pickMovement(G2_LEFTTURN);
	assert(result == G2_LEFTTURN);

	//Test with turnright function
	result = pickMovement(G2_RIGHTTURN);
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
		id = i;
		assert(foward_with_time() == i);
	}
}

void test_numeric_backward() {
	for (int i = 0; i < 20; i++) {
		id = i;
		assert(foward_with_time() == 100 + i);
	}
}

/* This is a cheat code for function with number:
*  foward will range 0-19 for the time corresponding of group3 0-19
*  backward will range 100-119 for the time corresponding group3 0-19 
*  turnLeft will range 200-219 for the angle corresponding group3 0-19
*  turnRight will range 300-319 for the angle corresponding group3 0-19
*/
void test_distance_foward() {
	for (int i = 0; i < 20; i++) {
		id = i;
		assert(foward_with_distance() == 600 + i);
	}
}

void test_distance_backward() {
	for (int i = 0; i < 20; i++) {
		id = i;
		assert(foward_with_distance() == 700 + i);
	}
}
void test_numeric_turnLeft() {
	for (int i = 0; i < 20; i++) {
		id = i
		assert(turnLeft_with_degree() == 200 + i);
	}
}

void test_numeric_turnRight() {
	for (int i = 0; i < 20; i++) {
		id = i;
		assert(turnRight_with_degree() == 300 + i);
	}
}

void test_action() {
	int result, numeric;

	//test action with group0
	result = action(GROUP_0, 0);
	assert(result == GROUP_0);

	//test action with group1
	result = action(GROUP_1, G1_FOWARD);
	assert(result == 0);
	result = action(GROUP_1, G1_BACKWARD);
	assert(result == 100);
	result = action(GROUP_1, G1_LEFTTURN);
	assert(result == 200);
	result = action(GROUP_1, G1_RIGHTTURN);
	assert(result == 300);
	result = action(GROUP_1, G1_TURNBACKLEFT);
	assert(result == 400);
	result = action(GROUP_1, G1_TURNBACKRIGHT);
	assert(result == 500);

	//test action with group2
	result = action(GROUP_2, G2_FOWARD);
	assert(result == G2_FOWARD);
	result = action(GROUP_2, G2_BACKWARD);
	assert(result == G2_BACKWARD);
	result = action(GROUP_2, G2_LEFTTURN);
	assert(result == G2_LEFTTURN);
	result = action(GROUP_2, G2_RIGHTTURN);
	assert(result == G2_RIGHTTURN);

	/* test action with group3 with foward
	 * In reality, the user will call the function, then it will trigger to the group3_group of numbers
	 * then the action function will recoginize the number and set the number variable in each function_with_number
	 * will set the number first then recall the function with foward_with_number
	 * then with the set number the function will run instead of call the action again.
	 */
	action(GROUP_3, G3_10);
	result = action(GROUP_2, G2_FOWARD);
	assert(result == G3_10);

	/* test action with group3 with backward
	* In reality, the user will call the function, then it will trigger to the group3_group of numbers
	* then the action function will recoginize the number and set the number variable in each function_with_number
	* will set the number first then recall the function with foward_with_number
	* then with the set number the function will run instead of call the action again.
	*/
	action(GROUP_3, G3_19);
	result = action(GROUP_2, G2_BACKWARD);
	assert(result == 100 + G3_19);

	/* test action with group3 with turnLeft
	* In reality, the user will call the function, then it will trigger to the group3_group of numbers
	* then the action function will recoginize the number and set the number variable in each function_with_number
	* will set the number first then recall the function with foward_with_number
	* then with the set number the function will run instead of call the action again.
	*/
	action(GROUP_3, G3_5);
	result = action(GROUP_2, G2_LEFTTURN);
	assert(result == 200 + G3_5);

	/* test action with group3 with turnRight
	* In reality, the user will call the function, then it will trigger to the group3_group of numbers
	* then the action function will recoginize the number and set the number variable in each function_with_number
	* will set the number first then recall the function with foward_with_number
	* then with the set number the function will run instead of call the action again.
	*/
	action(GROUP_3, G3_15);
	result = action(GROUP_2, G2_RIGHTTURN);
	assert(result == 300 + G3_15);
}

int main() {
	test_trigger();
	test_basic();
	test_numeric();
	test_numeric_foward();
	test_distance_backward();
	test_distance_foward();
	test_numeric_backward();
	test_numeric_turnLeft();
	test_numeric_turnRight();
	test_action();
	return 0;
}