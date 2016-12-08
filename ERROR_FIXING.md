Here is the file to include all the erro I encountered during project:

FIrst, EasyVR not detected:

1. Make sure that all the connectors between EasyVR and Arduino Shield are closed.

2. Make sure that all he connectors between EasyVR and BOE shield for robot are closed.

3. Put the Arduino, then EasyVR on top of it, and then the BOE shield on top of the EasyVR shield.

4. WIthout speaker, make sure you connect the two wires from the speaker plugin spot to one the GND and another one to the farest hold after IRONE spot on the EasyVR, fail to do so will make the EasyVR not working at all

5. Check your code, since your EasyVR already used 12, 13 digital ports, these ports have to be fixed. DO NOT attach anything you want to use with the port of 12, 13 or it cannot detect your EasyVR.