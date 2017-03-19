// PORT SELECTIONS
int pot01port = 0;
int joyXport = 1;
int joyYport = 2;

// SENSOR VALUES
int pot01val = 0;
int pot01lastVal = 0;
int joyXval = 0;
int joyXlastVal = 0;
int joyYval = 0;
int joyYlastVal = 0;

int pot01val = 0;		//Initial poteniometer value.
int pot01lastVal = 0;	//Used to test if our value has been changed.

void setup() {
	Serial.begin(9600); //Sets the speed of the midi port to the same as we will be using Hairless Midi
}

void loop() {
	pot01val = analogRead(1)/8;			// We divide by 8 to convert the 0-1023 analog message to 0-127 used for midi protocol
	if(pot01val != pot01lastVal) {			// If val != lastVal, the pot knob has been turned, and we need to send the new value to our software.
		MIDImessage(1,1,pot01val);		// (1) 176 CC command, (2) midi channel, (3) value to be updated
		pot01lastVal = pot01val; //reset
	}      
	delay(10); //A short delay is added here to prevent data resends for small changes in analogue input that may be due to accidental nudges.
}

void MIDImessage(byte command, byte data1, byte data2) { //passes out our values through standard midi command
	Serial.write(command);
	Serial.write(data1);
	Serial.write(data2);
}
