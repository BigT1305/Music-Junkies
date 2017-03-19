void setup() {
	// put your setup code here, to run once:
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	int n = 80;
	
	digitalWrite(LED_BUILTIN, HIGH);
	delay(1*n);
	digitalWrite(LED_BUILTIN, LOW);
	delay(1*n);

	digitalWrite(LED_BUILTIN, HIGH);
	delay(1*n);
	digitalWrite(LED_BUILTIN, LOW);
	delay(1*n);

	digitalWrite(LED_BUILTIN, HIGH);
	delay(2*n);
	digitalWrite(LED_BUILTIN, LOW);
	delay(2*n);

	digitalWrite(LED_BUILTIN, HIGH);
	delay(2*n);
	digitalWrite(LED_BUILTIN, LOW);
	delay(2*n);
	
	digitalWrite(LED_BUILTIN, HIGH);
	delay(2*n);
	digitalWrite(LED_BUILTIN, LOW);
	delay(2*n);
}
