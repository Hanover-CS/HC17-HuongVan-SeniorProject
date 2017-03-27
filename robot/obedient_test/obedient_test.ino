/*
 * obedient_test.ino
 * This is the robot sketch test that we will use to test how robot repsonse to each function.
 * This need to be done one at a time. To start, pick the movement you want to test and comment out the rest of the movements in the loop function.
 * Upload the code and test it with your robot. When you have a good sense of it works properly, comment out that movement and uncomment the next
 * testing movement. Keep testing each movement one at a time until you see that the Robot works properly.
 * 
 */
#include <Obedient.h>
/*
 * This is a test file for function directing movement in 
 * Obedient library released to public
 * Created by Hoang N.H. Van November 17, 2016
 * Updated in Nov 17, 2016
 */
//Declare obedient here 
Obedient obedient(10, 11);

/*
 * setup function
 * This will set up the robot and get it ready to test with movements
 */
void setup() {
  // put your setup code here, to run once:
  obedient.attachServo();
}

/*
 * loop function
 * This function will run forever until the Robot is stopped.
 * It will get call the testing movement and keep doing that until you stop the robot so that you can see
 * how the robot behaves with each movement.
 */
void loop() {
  // put your main code test here, to run repeatedly:

  //Test foward function, it will run for 10 second
  obedient.foward();
  obedient.foward();
  obedient.stopSecond(5);

  //Test backward fuction non stop
  obedient.backwardNonStop();

  //Test backward fuction with distance
  obedient.backwardDistance(5);

  //Test foward fuction with distance
  obedient.fowardDistance(10);

  //Test foward fuction non stop
  obedient.fowardNonStop();
  
  //Test backward fuction it will run for 15 second
  obedient.backward();
  obedient.stopSecond(5);

  //Test foward function with second
  obedient.fowardSecond(10);
  obedient.stop();

  //Test backward function with second
  obedient.backwardSecond(10);
  obedient.stop();

  //Test turn back from the left
  obedient.turnBackLeft();
  obedient.stopSecond(2);

  //Test turn back from the right
  obedient.turnBackRight();
  obedient.stop();

  //Test turn left
  obedient.turnLeft();
  obedient.stop();

  //Test turn right
  obedient.turnRight();
  obedient.stopSecond(2);

  //Test circle around from the left
  obedient.circleLeft();
  obedient.stop();

  //Test circle around from the right
  obedient.circleRight();
  obedient.stop();
}
