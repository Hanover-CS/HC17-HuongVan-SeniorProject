/*
 * This is a test file for function directing movement in 
 * Obedient library released to public
 * Created by Hoang N.H. Van November 17, 2016
 * Updated in Nov 17, 2016
 */
#include "Obedient.h"
Obedient obedient(13, 12)
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code test here, to run repeatedly:

  //Test foward function, it will run for 10 second
  obedient.foward();
  obedient.foward();

  //Test backward fuction it will run for 15 second
  obedient.foward();
  obedient.foward();

  //Test foward function with second
  obedient.fowardSecond(10);

  //Test backward function with second
  obedient.backwardSecond(10);

  //Test turn back from the left
  obedient.turnBackLeft();

  //Test turn back from the right
  obedient.turnBackRight();

  //Test turn left
  obedient.turnLeft();

  //Test turn right
  obedient.turnRight();

  //Test circle around from the left
  obedient.circleLeft();

  //Test circle around from the right
  obedient.circleRight();
}
