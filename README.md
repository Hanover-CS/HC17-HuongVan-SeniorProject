# hc07-Obedient
Hoang Van Senior Project Proposal

This is my senior thesis. I want to build a speech-driven robot using Arduino BOE shield Bot, and EasyVR 3.0 Speech Recognition Shield based on Hidden Markov Model, which is widely used in speech recognition field.

Goals of this project are to be able to direct movement of the robot using speech and to design a series of experiments to test this speech-driven robotic system.

How to run the project:

There are two parts in my project. One is the code for the robot, and the other is the code for the automatic speech recognition (ASR). The following will show you how to use:

1. The code for the robot.

2. The code for the ASR.

3. The interactive code between ASR and the robot.

The robot:

There is a library I created, simply download the library folder and place inside the library directory of your Arduino project.

In Windows, the library folder should be in My Documents/Arduino/libraries.

In OSX, the library folder should be in /~Documents/Arduino/libraries.

For more information, please check out the link below as the instruction how to place an additional library in your Arduino project:

https://www.arduino.cc/en/hacking/libraries

After placing Obedient library into your libraries repository, now you can include the "Obedient.h" in your sketch.

Here is the example code of to include the "Obedient.h":
#include "Obedient.h"
//13 is the pin number you want to connect the left servo, and 14 is the pin number you want to connect to right servo
Obedient obedient(13, 14);
void setup()
{

}
void loop()
{
	//Obedient will move foward and stop 2 second
	obedient.foward();
	obedient.stop(2);

	//Obedient will move backward
	obedient.backward();
	obedient.stop(2);
}

These followings are the methods you can use when playing with Obedient:
1. Methods with quantity
	fowardSecond(int second);
	backwardSecond(int second);

2. Methods without quantity
	foward();
	backward();
	turnBackLeft();
	turnBackRight();
	turnLeft();
	turnRight();
	circleLeft();
	circleRight();

