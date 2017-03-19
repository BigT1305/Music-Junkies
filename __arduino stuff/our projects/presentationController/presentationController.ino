// MIDI: GENERAL SETUP
#include <MIDI.h>
#define MIDI_ENABLE 12
MIDI_CREATE_DEFAULT_INSTANCE(); // Created and binds the MIDI interface to the default hardware Serial port

// ULTRASONIC SETUP
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

// SENSORS: (1) ARD. PORT, (2) CONT. CTRL. ASGNMT., (3) CURR VALUE, (4) LAST VALUE

//int usonic01port;
int usonic01cc = 16;
int usonic01val = 0;
int usonic01lastVal = 0;

int pot01port = 0;
int pot01cc = 1;
int pot01val = 0;     // current poteniometer value
int pot01lastVal = 0; // tests for value change

int joyXport = 1;
int joyXcc = 7;
int joyXval = 0;
int joyXlastVal = 0;

int joyYport = 2;
int joyYcc = 10;
int joyYval = 0;
int joyYlastVal = 0;


void setup() {
	MIDI.begin();  // Listen to all incoming messages
	Serial.begin(115200);
}

void loop() {

/*	// ULTRASONIC 01
	usonic01val = sr04.Distance(); //convert1023to127invert(analogRead(pot01port));     // We divide by 8 to convert the 0-1023 analog message to 0-127 used for midi protocol
	if (usonic01val > 127) usonic01val = 127; // limit ultra sonic sensor's top value to 127
	if(usonic01val != usonic01lastVal) {      // If val != lastVal, the pot knob has been turned, and we need to send the new value to our software.
		Serial.print("usonic: ");
		Serial.print(usonic01val);
		Serial.println("cm");
//		MIDImessage(usonic01cc, 1, usonic01val);    // (1) CC, (2) midi channel, (3) controller value
//		MIDI.sendControlChange(1, usonic01cc, usonic01val);
		usonic01lastVal = usonic01val; //reset
	}*/
	
	// POT 01
	pot01val = convert1023to127invert(analogRead(pot01port));     // We divide by 8 to convert the 0-1023 analog message to 0-127 used for midi protocol
	if(pot01val != pot01lastVal) {      // If val != lastVal, the pot knob has been turned, and we need to send the new value to our software.
		Serial.print("pot 01: ");
		Serial.println(pot01val);
//		MIDImessage(pot01cc, 1, pot01val);    // (1) CC, (2) midi channel, (3) controller value
//		MIDI.sendControlChange(1, pot01cc, pot01val);
		pot01lastVal = pot01val; //reset
	}
	
	// JOYSTICK X
	joyXval = convert1023to127(analogRead(joyXport));     // We divide by 8 to convert the 0-1023 analog message to 0-127 used for midi protocol
	if(joyXval != joyXlastVal) {      // If val != lastVal, the pot knob has been turned, and we need to send the new value to our software.
		Serial.print("jystkX: ");
		Serial.println(joyXval);
//		MIDImessage(joyXcc, 1, joyXval);    // (1) CC, (2) midi channel, (3) controller value
//		MIDI.sendControlChange(1, joyXcc, joyXval);
		joyXlastVal = joyXval; //reset
	}

	// JOYSTICK Y
	joyYval = convert1023to127(analogRead(joyYport)); // get reading & convert 0-1023 to 0-127
	if(joyYval != joyYlastVal) {  // if reading has changed since last cycle, make reading into midi message
		Serial.print("jystkY: ");
		Serial.println(joyYval);
//		MIDImessage(joyYcc, 1, joyYval);    // (1) CC, (2) midi channel, (3) controller value
//		MIDI.sendControlChange(1, joyYcc, joyYval);
		joyYlastVal = joyYval; //reset
	}
	
	delay(10); // arduino cycle delay in ms.
}

void MIDImessage(byte command, byte data1, byte data2) { // passes out our values through standard midi command
	Serial.write(command);
	Serial.write(data1);
	Serial.write(data2);
}

int convert1023to127 (int original) {
	int newVal = original / 8;
	return newVal;
}

int convert1023to127invert (int original) {
	int newVal = (((original / 8) -127) * -1);
	return newVal;
}
