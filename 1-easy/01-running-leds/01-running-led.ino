const short delayTime = 500;
const short ledNumber = 8;
const short ledPins[ledNumber] = {3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
  for (int i = 0; i < ledNumber; i++) {
  	pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledNumber; i++) {
  	digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
  
  for (int i = ledNumber - 2; i > 0; i--) {
  	digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}