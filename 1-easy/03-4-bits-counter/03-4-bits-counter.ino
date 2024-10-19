const short ledPins[4] = {11, 10, 9, 8};
const short delayTime = 1000;
uint8_t number = 0;

void setup() {
  for (int i = 0; i < 4; i++) {
  	pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  if (++number > 15) number = 0;
  for (int i = 0; i < 4; i++) {
  	digitalWrite(ledPins[i], bitRead(number, i));
  }
  delay(delayTime);
}