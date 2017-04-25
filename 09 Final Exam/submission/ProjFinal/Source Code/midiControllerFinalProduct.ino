#include <NewPing.h>

// SONAR VARIABLES
#define TRIGGER_PIN_ONE 20 	//define TRIGGER_PIN (sonarOne) to digitalIn 20
#define ECHO_PIN_ONE 21 	//define ECHO_PIN (sonarOne) to digitalIn 21
#define TRIGGER_PIN_TWO 22 //define TRIGGER_PIN_TWO (sonarTwo) to digitalIn 22
#define ECHO_PIN_TWO 23 //define ECHO_PIN_TWO to digitalIn 23
#define MAX_DISTANCE 50 //set max sonar distance to 50cm
NewPing sonarOne(TRIGGER_PIN_ONE, ECHO_PIN_ONE, MAX_DISTANCE); //intialize sonarOne
NewPing sonarTwo(TRIGGER_PIN_TWO, ECHO_PIN_TWO, MAX_DISTANCE); //initalize sonarTwo

int distanceOne = 0;
int midiValueOne = 0;
int distanceTwo = 0;
int midiValueTwo = 0;

// CURRENT VALUES FOR CC CONTROLERS
byte currentIn1 = 0;
byte currentIn2 = 0;
byte currentIn3 = 0;
byte currentIn4 = 0;
byte currentIn5 = 0;

// PREV. VALUES FOR CC CONTROLLERS. USED TO DETECT CHANGES
byte lastIn1 = 0;
byte lastIn2 = 0;
byte lastIn3 = 0;
byte lastIn4 = 0;
byte lastIn5 = 0;

// KEYS (CHOOSE INPUT PIN)
int keyOne = 4;
int keyTwo = 5;
int keyThree = 6;
int keyFour = 7;
int keyFive = 8;
int keySix = 10;
int keySeven = 11;

// KEY VALUES (1 IS OFF)
int keyValOne = 1;
int keyValTwo = 1;
int keyValThree = 1;
int keyValFour = 1;
int keyValFive = 1;
int keyValSix = 1;
int keyValSeven = 1; //variable for reading the pin status

//Initalize key's last values (pushDown) used to compare staes
int keyLastValOne = 0;
int keyLastValTwo = 0;
int keyLastValThree = 0;
int keyLastValFour = 0;
int keyLastValFive = 0;
int keyLastValSix = 0;
int keyLastValSeven = 0;



void setup() {
	// Serial.begin(115200);
	Serial.begin(9600);

	// Initialization of inputPins (PushDown *keys*)
	pinMode(keyOne, INPUT);    
	pinMode(keyTwo, INPUT);
	pinMode(keyThree, INPUT);
	pinMode(keyFour, INPUT);
	pinMode(keyFive, INPUT);
	pinMode(keySix, INPUT);
	pinMode(keySeven, INPUT);
}


void loop() {

	// PROCESS SONAR DATA

	distanceOne = sonarOne.ping_cm(); //convert the time it took sonarOne's echo signal to return to sensor to distance (cm) 
	distanceTwo = sonarTwo.ping_cm();//convert the time it took sonarTwo's echo signal to return to sensor to distance (cm) 
	midiValueOne = (((distanceOne/.4) - 127 ) * -1); //convert distance to 0 - 127 for MIDI
	midiValueTwo = (((distanceTwo/.4) - 127 ) * -1); //convert distanceTwo to 0 - 127 for MIDI

	// sonar 1
	if (midiValueOne == 127) { // no input is detected, do nothing
	}
	else {
		usbMIDI.sendControlChange(10, midiValueOne, 1);  // (cc#, ccVal, ccChan)
	}

	// sonar 2
	if (midiValueTwo == 127) { // no input is detected, do nothing
	}
	else {
		usbMIDI.sendControlChange(8, midiValueTwo, 1);
	}



	// PROCESS CONTINUOUS CONTROLLER DATA

	currentIn1 = (analogRead(A0) / 8);
	if (currentIn1 != lastIn1) {
		lastIn1 = currentIn1;
		usbMIDI.sendControlChange(11, lastIn1, 1);  // (cc#, ccVal, ccChan)
	}

	currentIn2 = (analogRead(A4) / 8);
	if (currentIn2 != lastIn2) {
		lastIn2 = currentIn2;
		usbMIDI.sendControlChange(12, lastIn2, 1);  // (cc#, ccVal, ccChan)
	}

	currentIn3 = (analogRead(A3) / 8);
	if (currentIn3 != lastIn3) {
		lastIn3 = currentIn3;
		usbMIDI.sendControlChange(13, lastIn3, 1);  // (cc#, ccVal, ccChan)
	}

	currentIn4 = (analogRead(A2) / 8);
	if (currentIn4 != lastIn4) {
		lastIn4 = currentIn4;
		usbMIDI.sendControlChange(14, lastIn4, 1);  // (cc#, ccVal, ccChan)
	}

	currentIn5 = (analogRead(A1) / 8);
	if (currentIn5 != lastIn5) {
		lastIn5 = currentIn5;
		usbMIDI.sendControlChange(15, lastIn5, 1);  // (cc#, ccVal, ccChan)
	}



	// PROCESS KEY CHANGES
	keyValOne = digitalRead(keyOne);  // read input value
	keyValTwo = digitalRead(keyTwo);  // read input value
	keyValThree = digitalRead(keyThree);  // read input value
	keyValFour = digitalRead(keyFour);  // read input value
	keyValFive = digitalRead(keyFive);  // read input value
	keyValSix = digitalRead(keySix);  // read input value
	keyValSeven = digitalRead(keySeven);  // read input value
	int currValOne = keyValOne;
	int currValTwo = keyValTwo;
	int currValThree = keyValThree;
	int currValFour = keyValFour;
	int currValFive = keyValFive;
	int currValSix = keyValSix;
	int currValSeven = keyValSeven;

	// button 1
	if (currValOne != keyLastValOne) {
		// if released, send A2 noteOff
		if (currValOne == 1)
			usbMIDI.sendNoteOff(57, 0, 1);
		// if Pushed, send A2 noteOn
		else
			usbMIDI.sendNoteOn(57, 127, 1);
		keyLastValOne = currValOne; // update last value with current value
	}

	// button 2
	if (currValTwo != keyLastValTwo) {
		// if released, send B2 noteOff
		if (currValTwo == 1)
			usbMIDI.sendNoteOff(59, 0, 1);
		// if pushed, send B2 noteOn
		else
			usbMIDI.sendNoteOn(59, 127, 1);
		keyLastValTwo = currValTwo; // update last value with current value
	}

	// button 3
	if (currValThree != keyLastValThree) {
		// if released, send C3 noteOff
		if (currValThree == 1)
			usbMIDI.sendNoteOff(61, 0, 1);
		// if pushed, send B2 noteOn
		else
			usbMIDI.sendNoteOn(61, 127, 1);
		keyLastValThree = currValThree; // update last value with current value
	}

	// button 5
	if (currValFive != keyLastValFive) {
		// if released, send E3 noteOff
		if (currValFive == 1)
			usbMIDI.sendNoteOff(64, 0, 1);
		// if pushed, send B2 noteOn
		else
			usbMIDI.sendNoteOn(64, 127, 1);
		keyLastValFive = currValFive; // update last value with current value
	}



	// FREQUENCY INTERVAL IN MS.
	delay(25);

} // end loop