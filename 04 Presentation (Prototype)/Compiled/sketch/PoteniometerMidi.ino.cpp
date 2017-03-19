#include <Arduino.h>
#line 1 "/Users/Wunstel/Desktop/PoteniometerMidi/PoteniometerMidi.ino"
#line 1 "/Users/Wunstel/Desktop/PoteniometerMidi/PoteniometerMidi.ino"
int val = 0; //Initial poteniometer value.
int lastVal = 0; //Used to test if our value has been changed.

#line 4 "/Users/Wunstel/Desktop/PoteniometerMidi/PoteniometerMidi.ino"
void setup();
#line 9 "/Users/Wunstel/Desktop/PoteniometerMidi/PoteniometerMidi.ino"
void loop();
#line 19 "/Users/Wunstel/Desktop/PoteniometerMidi/PoteniometerMidi.ino"
void MIDImessage(byte command, byte data1, byte data2);
#line 4 "/Users/Wunstel/Desktop/PoteniometerMidi/PoteniometerMidi.ino"
void setup() {
	Serial.begin(9600); //Sets the speed of the midi port to the same as 
											//we will be using Hairless Midi
}

void loop() {
	val = analogRead(0)/8; //We divide by 8 to convert the 0-1023 analog message to 0-127 used for midi protocol
	if(val != lastVal) { //If val != lastVal, the pot knob has been turned, and we need to send the new value to our software.
		MIDImessage(176,1,val); //176 (param 1) represent the CC command, 1 (param 2) represents channel, and val(param 3) is the value to be updated
		lastVal = val; //reset
	}      
	delay(10); //A short delay is added here to prevent data resends for small changes in analogue input 
						 //that may be due to accidental nudges.
}

void MIDImessage(byte command, byte data1, byte data2) { //passes out our values through standard midi command
	Serial.write(command);
	Serial.write(data1);
	Serial.write(data2);
}
