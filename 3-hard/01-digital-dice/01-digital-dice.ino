const uint8_t SSD_common[2] = {3, 4};
const uint8_t SSD_segment[7] = {5, 6, 7, 8, 9, 10, 11};
const uint8_t buttonPin = 13;
const uint8_t buzzerPin = 2;

short currentNumber = 0;

const uint8_t digitPatterns[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

void showDigit(int digit, int position) {
  digitalWrite(SSD_common[0], HIGH);
  digitalWrite(SSD_common[1], HIGH);

  uint8_t pattern = digitPatterns[digit];
  for (int i = 0; i < 7; i++) {
    digitalWrite(SSD_segment[i], pattern & (1 << i) ? HIGH : LOW);
  }

  digitalWrite(SSD_common[position], LOW);
}

void showNumber(int number) {
  int digit1 = number / 10;     
  int digit2 = number % 10;    

  showDigit(digit1, 0);
  delay(2); 

  showDigit(digit2, 1);
  delay(2); 
}

void setup() {
  pinMode(SSD_common[0], OUTPUT);
  pinMode(SSD_common[1], OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < 7; i++) {
    pinMode(SSD_segment[i], OUTPUT);
  } 

  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin)) {
    if (++currentNumber > 99)
      currentNumber = 0;
  } 
  showNumber(currentNumber);
  digitalWrite(buzzerPin, currentNumber % 11 == 0 && !digitalRead(buttonPin));
}