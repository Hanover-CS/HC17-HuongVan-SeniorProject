# hc07-Obedient
#Hoang Van Senior Project Proposal
Current Version: 1.0 2/3/2017

This is my senior thesis. I want to build a speech-driven robot using Arduino BOE shield Bot, and EasyVR 3.0 Speech Recognition Shield based on Hidden Markov Model, which is widely used in speech recognition field.

Goals of this project are to be able to direct movement of the robot using speech and to design a series of experiments to test this speech-driven robotic system.

##Prerequisites
You will need to download and place the [EasyVR library](https://github.com/RoboTech-srl/EasyVR-Arduino/releases/download/v1.9.1/EasyVR-Arduino-library-1.9.1.zip) into your Arduino libraries.
Also, need to run the small demo from [EasyVR library](http://www.veear.eu/files/EasyVR%203%20User%20Manual%201.0.14.pdf) before proceeding with this project.

##Getting Started:

There are two parts in my project. One is the code for the robot, and the other is the code for the automatic speech recognition (ASR). The following will show you how to use:

1. The code for the robot.

2. The code for the ASR, I used [EasyVR shield](http://www.veear.eu/files/EasyVR%203%20User%20Manual%201.0.14.pdf).

3. The interactive code between ASR and the robot.

The robot:

There is a library I created, simply download the library folder and place inside the library directory of your Arduino project.

In Windows, the library folder should be in My Documents/Arduino/libraries.

In OSX, the library folder should be in /~Documents/Arduino/libraries.

For more information, please check out the link below as the instruction how to place an additional library in your Arduino project: [libraries](https://www.arduino.cc/en/hacking/libraries)

After placing Obedient library into your libraries repository, now you can include the "Obedient.h" in your sketch.

##How to use the [Obedient library](https://github.com/vanh17/hc07-Obedient/):

Check out the test file in robot/test for how to include "Obedient.h" in your sketch.

These followings are the methods you can use when playing with Obedient:

1. Methods with quantity
	* fowardSecond(int second);
	* backwardSecond(int second);

2. Methods without quantity
	* foward();
	* backward();
	* turnBackLeft();
	* turnBackRight();
	* turnLeft();
	* turnRight();
	* circleLeft();
	* circleRight();

##Versioning:

I use [Github](github.com) to control the version of the project.

##Issues:

If you have any issues, please post them [here](https://github.com/vanh17/hc07-Obedient/issues)

##Author:
[Hoang Van](https://github.com/vanh17/)