// MIDI SETUP
#include <MIDI.h>
#define MIDI_ENABLE 12
MIDI_CREATE_DEFAULT_INSTANCE(); // Created and binds the MIDI interface to the default hardware Serial port

// SENSORS: PORT, VALUE, LAST_VALUE
int pot01port = 0;
int pot01val = 0;   //Initial poteniometer value.
int pot01lastVal = 0; //Used to test if our value has been changed.

int joyXport = 1;
int joyXval = 0;
int joyXlastVal = 0;

int joyYport = 2;
int joyYval = 0;
int joyYlastVal = 0;


void setup() {
	MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages
	Serial.begin(9600);
}

void loop() {
		// MIDI.sendNoteOn(42, 127, 1); // Send note 42 with velocity 127 on channel 1
		// MIDI.read(); // Read incoming messages


	pot01val = analogRead(0);     // We divide by 8 to convert the 0-1023 analog message to 0-127 used for midi protocol
	if(pot01val != pot01lastVal) {      // If val != lastVal, the pot knob has been turned, and we need to send the new value to our software.
//		 MIDImessage(1,1,pot01val);    // (1) 176 CC command, (2) midi channel, (3) value to be updated
		MIDI.sendControlChange(16,pot01val,1);
		pot01lastVal = pot01val; //reset
	}      
	delay(10); //A short delay is added here to prevent data resends for small changes in analogue input that may be due to accidental nudges.
}

void MIDImessage(byte command, byte data1, byte data2) { //passes out our values through standard midi command
	Serial.write(command);
	Serial.write(data1);
	Serial.write(data2);
}
