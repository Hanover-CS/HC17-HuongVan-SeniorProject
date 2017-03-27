# hc07-Obedient
#Hoang Van Senior Project Proposal
Current Version: 1.0 2/3/2017

This is my senior thesis. I want to build a speech-driven robot using Arduino BOE shield Bot, and EasyVR 3.0 Speech Recognition Shield based on Hidden Markov Model, which is widely used in speech recognition field.

Goals of this project are to be able to direct movement of the robot using speech and to design a series of experiments to test this speech-driven robotic system.

##Prerequisites
You will need to download and place the [EasyVR library](https://github.com/RoboTech-srl/EasyVR-Arduino/releases/download/v1.9.1/EasyVR-Arduino-library-1.9.1.zip) into your Arduino libraries.
Also, need to run the small demo from [EasyVR library](http://www.veear.eu/files/EasyVR%203%20User%20Manual%201.0.14.pdf) before proceeding with this project.
Download the [Obedient library](https://github.com/vanh17/hc07-Obedient) and place it into your Arduino libraries folder.
Download the [QueueArray](http://playground.arduino.cc/Code/QueueArray#Creation) and place it into your Arduino libraries folder. This library will help to implement the module that direct Obedient with multiple commands.

###Tips for this part:
1. Make sure that you have a latest version of Arduino softward and EasyVR library. Follow the link included to get the version that this project is built on.
2. The EasyVR **WILL NOT WORKING** until you have it soldered. You may find this video [how to solder](https://www.youtube.com/watch?v=oqV2xU1fee8)
3. Before working with the robot, make sure that you have your EasyVR shield can do a [small test with LED](https://github.com/vanh17/hc07-Obedient/tree/master/asr/asr_led_control).

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

The asr:

There is a sketch that you can use as an interface between Robot and ASR. This sketch can be found [here](https://github.com/vanh17/hc07-Obedient/tree/master/asr/easy_vr_command). It will automatically load all needed modules that are also created at the same repository. Simply open the sketch with Arduino software, compile and upload the sketch to your robot.

Before running any tests on the `Obedient`, make sure that you train your Obedient with custom words. To do this please follow this construction:

1. Download [EasyVR commander](http://www.veear.eu/downloads/), this is where you can train your robot with custom command.
2. Plug the Obedient to the laptop and open EasyVR commander, make sure the **PROC** is placed at **SW** port. This is important, if you want to work with EasyVR commander, the **PROC** has to be at **SW**. When you want to upload the code written in Arduino, the **PROC** has to be set to **PC**. Failed to so will make the Obedient cannot connect to your working laptop.
3. Training the Obedient with this list of commands in the following order:
. GROUP 0: TRIGGER
1. OBEDIENT: this is the trigger command
. GROUP 1: BASIC
1. FOWARD
2. BACKWARD
3. LEFTTURN
4. RIGHTTURN
5. BACKLEFT
6. BACKRIGHT
7. STOP
8. MAINMENU
9. GO
10. UPSPEED
11. DOWNSPEED
. GROUP 2: ADVANCED
1. FOWARD
2. BACKWARD
3. LEFTTURN
4. RIGHTURN
5. PICKUNIT
6. MAINMENU
. GROUP 3: NUMBERS
1. ONE
2. TWO
3. THREE
4. FOUR
5. FIVE
. GROUP 4: MAINMENU
1. BASIC
2. ADVANCED
3. SENSOR
4. LIST
. GROUP 7: UNITS
1. SECOND
2. INCH

###Tips for this part:
1. When you place robot board, EasyVR shield, and Arduino board makes sure that you place the EasyVR on top of the Arduino board, and then the robot board on top of the EasyVR. So the right order is bottom Arduino board, EasyVR middle, and Robot board is on top.
2. Besides the microphone, there is another thing that has one end is the white little box and the other are two chords. Make sure that you plug that into your EasyVR shield and connect the two chords: one to the **GND** port on the left side, and the other one to **IOREF**
3. Also you want to centralize the Robot wheel for the better performance. Check this [manual](https://www.parallax.com/sites/default/files/downloads/28125-Robotics-With-The-Boe-Bot-v3.0.pdf) how to centralize robot wheels

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