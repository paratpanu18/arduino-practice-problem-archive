const uint8_t ledNumber = 8;
const uint8_t ledPins[ledNumber] = {2, 3, 4, 5, 6, 7, 8, 9};


// Re-map range from analogRead (93 - 1023) to delayTime (50 - 1000 ms) corresponding to problem
float mapRange(float value, float m = 93, float n = 1023, float x = 50, float y = 1000) {
    return x + ((value - m) * (y - x)) / (n - m);
}

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < ledNumber; i++) {
  	pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < ledNumber; i++) {
  	digitalWrite(ledPins[i], HIGH);
    delay(mapRange(analogRead(A5)));
    digitalWrite(ledPins[i], LOW);
  }
  
  for (int i = ledNumber - 2; i > 0; i--) {
  	digitalWrite(ledPins[i], HIGH);
    delay(mapRange(analogRead(A5)));
    digitalWrite(ledPins[i], LOW);
  }
}