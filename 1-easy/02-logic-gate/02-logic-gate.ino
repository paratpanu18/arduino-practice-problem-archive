const short ledPins[6] = {2, 3, 4, 5, 6, 7};
const short buttonPins[3] = {8, 9, 10};
const short PB_A = 8, PB_B = 9, PB_OPERATOR = 10;

const short bitA1 = 2, bitA0 = 3, bitB1 = 4, bitB0 = 5, bitC1 = 6, bitC0 = 7;

short A = 0, B = 0, C = 0;
short selectedOperator = 0;

void setup() {
  for (int i = 0; i < 6; i++) {
  	pinMode(ledPins[i], OUTPUT);
  }
  
  for (int i = 0; i < 6; i++) {
  	pinMode(buttonPins[i], INPUT);
  }
}

void loop() {
  if (digitalRead(PB_A) == HIGH) {
    A += 1;
    if (A > 3) A -= 4;	// Prevent overflow
    delay(300);			// Basic debounce
  }

  if (digitalRead(PB_B) == HIGH) {
    B += 1;
    if (B > 3) B -= 4;	// Prevent overflow
    delay(300);			// Basic debounce
  }
  
  if (digitalRead(PB_OPERATOR) == HIGH) {
    selectedOperator += 1;
    if (selectedOperator > 3) selectedOperator -= 4;	// Prevent overflow
    delay(300);											// Basic debounce
  }
  
  digitalWrite(bitA1, bitRead(A, 1));  // A1
  digitalWrite(bitA0, bitRead(A, 0));  // A0
  digitalWrite(bitB1, bitRead(B, 1));  // B1
  digitalWrite(bitB0, bitRead(B, 0));  // B0
  
  switch (selectedOperator) {
  	case 0:  // AND
      C = A & B;
      break;
    case 1:  // OR
      C = A | B;
      break;
    case 2:  // XOR
      C = A ^ B;
      break;
    case 3:  // NOT
      C = ~A & 0x03;
      break;
  }
  
  digitalWrite(bitC1, bitRead(C, 1));
  digitalWrite(bitC0, bitRead(C, 0));
}