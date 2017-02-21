#include <Obedient.h>
/*
 * This is a test file for function directing movement in 
 * Obedient library released to public
 * Created by Hoang N.H. Van November 17, 2016
 * Updated in Nov 17, 2016
 */
 Obedient obedient(10, 11);
void setup() {
  // put your setup code here, to run once:
  obedient.attachServo();
}

void loop() {
  // put your main code test here, to run repeatedly:

  //Test foward function, it will run for 10 second
  obedient.foward();
  obedient.foward();
  obedient.stopSecond(5);

  //Test backward fuction it will run for 15 second
  obedient.foward();
  obedient.backward();
  obedient.stopSecond(5);

  //Test foward function with second
  obedient.fowardSecond(10);
  obedient.stop();

//  //Test backward function with second
//  obedient.backwardSecond(10);
//  obedient.stop();
//
//  //Test turn back from the left
//  obedient.turnBackLeft();
//  obedient.stopSecond(2);
//
//  //Test turn back from the right
//  obedient.turnBackRight();
//  obedient.stop();
//
//  //Test turn left
//  obedient.turnLeft();
//  obedient.stop();
//
//  //Test turn right
//  obedient.turnRight();
//  obedient.stop();
//
//  //Test circle around from the left
//  obedient.circleLeft();
//  obedient.stop();
//
//  //Test circle around from the right
//  obedient.circleRight();
//  obedient.stop();
}
