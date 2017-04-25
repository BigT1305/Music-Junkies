	#include <NewPing.h>

	//Declare current values for CC controlers
	byte currentIn1 = 0, currentIn2 = 0, currentIn3 = 0, currentIn4 = 0, currentIn5 = 0;

	//Declare lastIn values for CC controllers, used to check if a parameter has been changed *used to update*
	byte lastIn1 = 0, lastIn2 = 0, lastIn3 = 0, lastIn4 = 0, lastIn5 = 0;

	//Initialize digitalIns for each key (pushDown button)
	int keyOne = 4, keyTwo = 5, keyThree = 6, keyFour = 7, keyFive = 8, keySix = 10, keySeven = 11;   // choose the input pin (for a pushbutton)
	
	//Initialize each digitalIn to one (HIGH)
	int keyValOne = 1, keyValTwo = 1, keyValThree = 1, keyValFour = 1, keyValFive = 1, keyValSix = 1, keyValSeven = 1; //variable for reading the pin status
	
	//Initalize key's last values (pushDown) used to compare staes
	int keyLastValOne = 0, keyLastValTwo = 0,keyLastValThree = 0, keyLastValFour = 0, keyLastValFive = 0,keyLastValSix = 0,keyLastValSeven = 0;


	#define TRIGGER_PIN 20 	//define TRIGGER_PIN (sonarOne) to digitalIn 20
	#define ECHO_PIN 21 	//define ECHO_PIN (sonarOne) to digitalIn 21
	#define TRIGGER_PIN_TWO 22 //define TRIGGER_PIN_TWO (sonarTwo) to digitalIn 22
	#define ECHO_PIN_TWO 23 //define ECHO_PIN_TWO to digitalIn 23
	#define MAX_DISTANCE 50 //set max sonar distance to 50cm
 	NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); //intialize sonarOne
 	NewPing sonarTwo(TRIGGER_PIN_TWO, ECHO_PIN_TWO, MAX_DISTANCE); //initalize sonarTwo

void setup() {
 Serial.begin(115200);

  //Initialization of inputPins (PushDown *keys*)
  pinMode(keyOne, INPUT);    
  pinMode(keyTwo, INPUT);
  pinMode(keyThree, INPUT);
  pinMode(keyFour, INPUT);
  pinMode(keyFive, INPUT);
  pinMode(keySix, INPUT);
  pinMode(keySeven, INPUT);
}


void loop() {
/*CODE TO PROCESS SONAR DATA
 * -----------------------
 * -----------------------
 * -----------------------
 */
  //delay(50);
  int distance = sonar.ping_cm(); //convert the time it took sonarOne's echo signal to return to sensor to distance (cm) 
  int distanceTwo = sonarTwo.ping_cm();//convert the time it took sonarTwo's echo signal to return to sensor to distance (cm) 
  int midiValue = distance/.4; //convert distance to 0 - 127 for MIDI
  int midiValueTwo = distanceTwo/.4; //convert distanceTwo to 0 - 127 for MIDI


  //if no input is detected, do nothing
  if(midiValue == 0){
  	
  } 
  //if input (sonarOne) is detected, sent MIDI control change message on channel 10
  else {
  	//Serial.println(midiValue);
  	usbMIDI.sendControlChange(10, midiValue, 1);  // (cc#, ccVal, ccChan)
  }
  //if no input (sonarTwo) is detected, do nothing.
  if(midiValueTwo == 0) {
  
  } 
  //if input is detected (sonarTwo), send control change on channel 8.
  else {
  //	Serial.println(midiValueTwo);
  	usbMIDI.sendControlChange(8, midiValueTwo, 1);
  }


/*CODE TO PROCESS POTENTIOMETER CHANGES
 * -----------------------------------
 * -----------------------------------
 * -----------------------------------
 */
  //delay(50);
  
  
//Continuous Controller, can be mapped to any parameter and is used to automate
	int toPrint1 = analogRead(A0);
	currentIn1 = (toPrint1 / 8);
	if(currentIn1 != lastIn1){
		lastIn1 = currentIn1;
		usbMIDI.sendControlChange(11, lastIn1, 1);  // (cc#, ccVal, ccChan)
		//Serial.println(toPrint1);
	}
	

	int toPrint2 = analogRead(A4);
	currentIn2 = (toPrint2 / 8);
	if(currentIn2 != lastIn2){
		lastIn2 = currentIn2;
		usbMIDI.sendControlChange(12, lastIn2, 1);  // (cc#, ccVal, ccChan)
		//Serial.println(toPrint2);
	}
	

	int toPrint3 = analogRead(A3);
	currentIn3 = (toPrint3 / 8);
	if(currentIn3 != lastIn3){
		lastIn3 = currentIn3;
		usbMIDI.sendControlChange(13, lastIn3, 1);  // (cc#, ccVal, ccChan)
		//Serial.println(toPrint3);
	}
	
	int toPrint4 = analogRead(A2);
	currentIn4 = (toPrint4 / 8);
	if(currentIn4 != lastIn4){
		lastIn4 = currentIn4;
		usbMIDI.sendControlChange(14, lastIn4, 1);  // (cc#, ccVal, ccChan)
		//Serial.println(toPrint4);
	}
	
	int toPrint5 = analogRead(A1);
	currentIn5 = (toPrint5 / 8);
	if(currentIn5 != lastIn5){
		lastIn5 = currentIn5;
		usbMIDI.sendControlChange(15, lastIn5, 1);  // (cc#, ccVal, ccChan)
		//Serial.println(toPrint5);
	}
	
	

 // delay(50);

 /*CODE TO PROCESS KEY CHANGES
  * -------------------------
  * -------------------------
  */
  keyValOne = digitalRead(keyOne);  // read input value
  keyValTwo = digitalRead(keyTwo);  // read input value
  keyValThree = digitalRead(keyThree);  // read input value
  keyValFour = digitalRead(keyFour);  // read input value
  keyValFive = digitalRead(keyFive);  // read input value
  keyValSix = digitalRead(keySix);  // read input value
  keyValSeven = digitalRead(keySeven);  // read input value
  int currValOne = keyValOne, currValTwo = keyValTwo, currValThree = keyValThree, currValFour = keyValFour, currValFive = keyValFive, currValSix = keyValSix, currValSeven = keyValSeven;
  //Serial.println(keyValTwo);

//Check to see if button has been pushed
if(currValOne == keyLastValOne){
	//Serial.println("currValOne");
	
} else{

//if button has been released, send noteOff	
if(currValOne == 1) {

	  usbMIDI.sendNoteOff(57, 0, 9); //send A2 noteOff
	  keyLastValOne = currValOne; //update
	  
	  
} 

//if button has been pushed, send noteOn
else  {
		
	    usbMIDI.sendNoteOn(57, 127, 9); //send A2
		keyLastValOne = currValOne; //update
		
}
}

//Check to see if buttonTwo has been pushed
if(currValTwo == keyLastValTwo){
	
} else{

//if buttonTwo has been released, send noteOff	
if(currValTwo == 1) {
	  
	  usbMIDI.sendNoteOff(59, 0, 9); //send B2 noteOff
	  keyLastValTwo = currValTwo; //update
	  //Serial.println("1");
} 

//if buttonTwo has been released, send noteOn
else  {
	   
	    usbMIDI.sendNoteOn(59, 127, 9); //send B2 noteOn
		keyLastValTwo = currValTwo; //update
		//Serial.println("0");
}
}


//check to see if buttonThree has changed states
if(currValThree== keyLastValThree){
	
} else{

//if buttonThree has been relased, send noteOff
if(currValThree == 1) {

	 // Serial.println("1");
	  usbMIDI.sendNoteOff(60, 0, 9); //send C3 noteOff
	  keyLastValThree = currValThree; //update
	  
} 

//if buttonThree has been pushed, send noteOn
else  {

        //Serial.println("0");
	    usbMIDI.sendNoteOn(60, 127, 9); //send C3 noteOn
		keyLastValThree = currValThree; //update
}
}

//check to see if state of buttonFour has changed
if(currValFour == keyLastValFour){
	
} else{

//if buttonFour has been released, send noteOff	
if(currValFour == 1) {

	  usbMIDI.sendNoteOff(62, 0, 9); //send D3 noteOff
	  keyLastValFour = currValFour; //update
	  //Serial.println("1");
} 

//if buttonFour has been pushed down, send noteOn
else  {

	    usbMIDI.sendNoteOn(62, 127, 9); //send D3 noteOn
		keyLastValFour = currValFour; //update
		//Serial.println("0");
}
}

//check to see if buttonFive has changed states
if(currValFive == keyLastValFive){
	
} else{

//if buttonFive has been released, send noteOff
if(currValFive == 1) {

	  usbMIDI.sendNoteOff(64, 0, 9); //send E3 noteOff
	  keyLastValFive = currValFive; //update
	  Serial.println("1");
	  
}
//if buttonFive has been pushed down, send noteOn
else  {
	
	    usbMIDI.sendNoteOn(64, 127, 9); //send E3 noteOn
		keyLastValFive = currValFive; //update
		Serial.println("0");
}
}

//check to see if buttonSix state changed
if(currValSix == keyLastValSix){
	
} else{

//if buttonSix has been released, send noteOff
if(currValSix == 1) {
	
	  usbMIDI.sendNoteOff(64, 0, 9); //send F3 noteOff
	  keyLastValSix = currValSix; //update
	  Serial.println("off");
} 

//if buttonSix has been pushed, send noteOn
else  {
	
	    usbMIDI.sendNoteOn(64, 127, 9); //send F3 noteOn
		keyLastValSix = currValSix; //update
		Serial.println("on");
}
}

//Check to see if buttonSeven has changed states
if(currValSeven == keyLastValSeven){
	
} else{

//if buttonSeven has been released, send noteOff
if(currValSeven == 1) {

	  usbMIDI.sendNoteOff(67, 0, 9); //send G3 noteOff
	  keyLastValSeven = currValSeven; //update
	  
} 

//if buttonSeven has been pushed down, send noteOn
else  {
		
	    usbMIDI.sendNoteOn(67, 127, 9); //send G3 noteOn
		keyLastValSeven = currValSeven; //update
}
}

}//end body

