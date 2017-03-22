	byte currentIn1 = 0;
	byte lastIn1 = 0;
	byte currentIn2 = 0;
	byte lastIn2 = 0;
	byte currentIn3 = 0;
	byte lastIn3 = 0;
	byte currentIn4 = 0;
	byte lastIn4 = 0;
	byte currentIn5 = 0;
	byte lastIn5 = 0;

void setup() {
 Serial.begin(9600);
}

void loop() {
	
	int toPrint1 = analogRead(A0);
	currentIn1 = (toPrint1 / 8);
	if(currentIn1 != lastIn1){
		lastIn1 = currentIn1;
		usbMIDI.sendControlChange(11, lastIn1, 1);  // (cc#, ccVal, ccChan)
		Serial.println(toPrint1);
	}

	int toPrint2 = analogRead(A4);
	currentIn2 = (toPrint2 / 8);
	if(currentIn2 != lastIn2){
		lastIn2 = currentIn2;
		usbMIDI.sendControlChange(12, lastIn2, 1);  // (cc#, ccVal, ccChan)
		Serial.println(toPrint2);
	}

	int toPrint3 = analogRead(A3);
	currentIn3 = (toPrint3 / 8);
	if(currentIn3 != lastIn3){
		lastIn3 = currentIn3;
		usbMIDI.sendControlChange(13, lastIn3, 1);  // (cc#, ccVal, ccChan)
		Serial.println(toPrint3);
	}
	
	int toPrint4 = analogRead(A2);
	currentIn4 = (toPrint4 / 8);
	if(currentIn4 != lastIn4){
		lastIn4 = currentIn4;
		usbMIDI.sendControlChange(14, lastIn4, 1);  // (cc#, ccVal, ccChan)
		Serial.println(toPrint4);
	}
	
	int toPrint5 = analogRead(A1);
	currentIn5 = (toPrint5 / 8);
	if(currentIn5 != lastIn5){
		lastIn5 = currentIn5;
		usbMIDI.sendControlChange(15, lastIn5, 1);  // (cc#, ccVal, ccChan)
		Serial.println(toPrint5);
	}
	
	delay(5); 
}
