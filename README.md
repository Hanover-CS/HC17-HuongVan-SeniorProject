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
	* fowardNonStop(), this method will help you to set up for the Obedient keep going without stop at all
	* backwardNonStop(), this method will help you to set up for the Obedient keep going without stop at all

3. Private variables:
    * left : servo that will attach to the left wheel of the Obedient
    * right: servo that will attach to the right wheel of the Obedient
    * currentState: the current state of the Obedient, is it fowarding or backwarding, moving or at stop

You can also add more neccessary functions for your own project by putting your function declaration in `Obedient.h` file and then implement the function inside `Obedient.cpp` file.

##How to use the [Easy_vr_commands](https://github.com/vanh17/hc07-Obedient/tree/master/asr/easy_vr_command):

This interface currently has four groups of commands that represents four abilities that Obedient can do. After awakening the `Obedient` by say to it "Obedient", you will have four options to choose.

###Basic commands:
This group is GROUP_1. To use commands in this group, say 'Basic' to the `Obedient` and wait for the sound announcing that the word recognized.
1. "Foward", it will direct the `Obedient` to go foward in 5 seconds (default movement)
2. "Backward", it will direct the `Obedient` to go backward in 5 seconds (default movement)
3. "Left", it will direct the `Obedient` to turn left.
4. "Right", it will direct the `Obedient` to turn right.
5. "Back Left" it will turn `Obedient` back from the left.
6. "Back Right" it will turn `Obedient` back from the right.
7. "Main Menu", to go back to the Main Menu of option, simply say this one to the `Obedient`

###Advanced commands:
This group is GROUP_2. To use commands in this group, say 'Advanced' to the `Obedient` and wait for the sound announcing that the word recognized.
1. "Foward", it will direct the `Obedient` to go foward
2. "Backward", it will direct the `Obedient` to go backward
3. "Left", it will direct the `Obedient` to turn left.
4. "Right", it will direct the `Obedient` to turn right.
5. "Pick Unit", it will give you choose option to pick for the foward and backward command. 
5.1. "Second", the unit will now be in seconds
5.2. "Inch", the unit will now be in inches
6. "Main Menu", to go back to the Main Menu of option, simply say this one to the `Obedient`

After picking the movement, the `Obedient` will ask you for the number you want to run with that function.
1. "one", is for one second/inch in foward/backward function, but will equal to 50 in degree for turning
2. "two", is for two seconds/inches in foward/backward function, but will equal to 100 in degree for turning
3. "three", is for three seconds/inches in foward/backward function, but will equal to 150 in degree for turning
4. "four", is for four seconds/inches in foward/backward function, but will equal to 200 in degree for turning
5. "five", is for five seconds/inches in foward/backward function, but will equal to 250 in degree for turning

Example: 
1. "Advanced" .... beep(sound from the `Obedient`) ... "Foward" ...beep ... "Five": will direct the Obedient to move foward in 5 seconds.
2. "Advanced" .... beep....."Pick Unit".....beep... "Inch" ...beep ... "Foward" ...beep ... "Three": will direct the Obedient to move foward 3 inches.
3. "Advanced" .... beep(sound from the `Obedient`) ... "Left" ...beep ... "four": will direct the Obedient to turn left 200 degree.

###Sensor commands:
GROUP_5. To use commands in this group, say 'Sensor' to the `Obedient` and wait for the sound announcing that the word recognized.
1. "Foward", it will direct the `Obedient` to go foward forever until next command is received
2. "Backward", it will direct the `Obedient` to go backward until next command is received
3. "Left", it will direct the `Obedient` to turn left.
4. "Right", it will direct the `Obedient` to turn right.
5. "Stop", it will stop the `Obedient` current moving
6. "Main Menu", go back to the main menu

Example: 
1. "Sensor" .... beep(sound from the `Obedient`) ... "Foward" ...beep: will direct the Obedient to move foward.
2. "Sensor" .... beep....."Backward".....beep... "Left" ...beep: will direct the Obedient to move backward until the "left" is recognized, then the `Obedient` turns left and keep moving backward.
3. "Sensor" .... beep ... "Left" ...beep ... "foward".....beep......"backward"....."Stop"...."right": will direct the Obedient to turn left, then stop, then start to move foward until "backward" is recognized, then start to move backward. The movement continues until "stop" is recognized, then `Obedient` turn right and stop.

###List commands:
GROUP_6. To use commands in this group, say 'List' to the `Obedient` and wait for the sound announcing that the word recognized.
1. "Foward", it will direct the `Obedient` to go foward forever until next command is received
2. "Backward", it will direct the `Obedient` to go backward until next command is received
3. "Left", it will direct the `Obedient` to turn left.
4. "Right", it will direct the `Obedient` to turn right.
5. "Back Left" it will direct the `Obedient` to turn back from the left.
6. "Back right" it will direct the `Obedient` to turn back from the right.
5. "Go", it will start the action in the same order said.
6. "Main Menu", go back to the main menu

Example: 
1. "List" .... beep(sound from the `Obedient`) ... "Foward" ...beep ..."Backward"...beep...."Go" ... beep...: will direct the Obedient to move foward for five seconds, then move backward for 5 seconds then stop.
2. "List" .... beep....."Backward".....beep... "Left" ...beep "Foward" ... beep ... "Right".... beep ...."back right" .... beep....."back left"....beep...."Go"....beep: will direct the Obedient to move backward, then turn left, followed by fowarding, turn right and finally turn back from the right then `Obedient` resume to stop..

##Small Demo Talks:
Please follow this small demo talk to play with the `Obedient`, you are free to create your own script by combining different commands together. However, for your convenience, I make one for you:
1. "Obedient" : 

this will wake the `Obedient` up. Wait a beep before say the next command
2. "Advance"...beep..."Foward"....beep...."Three"...beep: 

this will turn on the advanced mode and ask the `Obedient` to move foward for three seconds.
3. "Pick Unit"...beep..."Inch"...beep...."Foward"...beep...."Five": 

this will change the unit from second to inch and ask `Obedient` to go foward now for 5 inches.
4. "Left"...beep..."Two": 

this will ask `Obedient` to turn left 100 degree.
5. "Right"... beep .. "Five":

this will ask `Obedient to turn right 250 degree.
6. "Main Menu": 

get back to the list of modes from which we can choose
7. "Basic"...beep...."Left".....beep...wait...."Right"......beep...wait..."Foward"....beep....wait..."Backward"....beep....wait....."Back left"....beep...wait...."Back Right"....beep...wait..."Main Menu": 

this will turn on the basic mode in the `Obedient`, then it will start by turning left, we has to wait until the action occurs before starting the next command. Turning right is followed, then `Obedient` will move foward next. Then backward. After finishing backward, it will turn back from the left and finally turn back from the right. The "main menu" in the end of the sequence get us back to list of modes.
8. "Sensor"...beep..."Foward"...."Backward"......"Left"........"Back Left"....."Foward"....."Right"....."Stop"....."Back right": 

this will turn on the sensor mode. Then the `Obedient` start to move foward, the action keep continue until it hears next command. Then it will go backward and keep doing that until it hears "left", then turn left, and keep moving backward. Then it will turn back from the left and keep moving backward. It then change the moving direction to go foward, then turn right and keep moving foward until it hears "Stop", the `Obedient` is put into halt. It then waiting for the next command or simply say "main menu" to get back to the list of modes.
9. "List"....."Foward"...."Right"....."Back Left"...."Back Right"....."Backward"....."Left"...."Go":

This will turn on the list mode. Then we give it commands in this order and end it by the trigger word "Go". Then the `Obedient` will follow this list of Action in the same order: foward, then turn right, turn back from the left, then turn back from the right, moving backward, turn left and then stop. Waiting for the next list of commands or simply say "main menu" to get back to the list of modes. 
##Versioning:

I use [Github](github.com) to control the version of the project.

##Issues:

If you have any issues, please post them [here](https://github.com/vanh17/hc07-Obedient/issues)

##Author:
[Hoang Van](https://github.com/vanh17/)