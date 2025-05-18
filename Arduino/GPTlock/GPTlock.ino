int but0 = 2;
int but1 = 4;
int but2 = 6;
int but3 = 8;
int green = 13;
int red = 12;
int count = 0;

void setup() {
  pinMode(but0, INPUT); // Configure buttons with pull-down resistors
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read button states (LOW means pressed because of pull-down resistors)
  bool b0 = (digitalRead(but0) == HIGH); // Button 0 pressed
  bool b1 = (digitalRead(but1) == HIGH); // Button 1 pressed
  bool b2 = (digitalRead(but2) == HIGH); // Button 2 pressed
  bool b3 = (digitalRead(but3) == HIGH); // Button 3 pressed

  // Debugging output
  Serial.print("b0=");
  Serial.print(b0);
  Serial.print("  b1=");
  Serial.print(b1);
  Serial.print("  b2=");
  Serial.print(b2);
  Serial.print("  b3=");
  Serial.print(b3);
  Serial.print("  count=");
  Serial.println(count);

  // Passcode sequence logic
  if (count == 0 && b2) {  // First button: but2
    count = 1;
    delay(200); // Debounce delay
  }
  else if (count == 1 && b0) {  // Second button: but0
    count = 2;
    delay(200);
  }
  else if (count == 2 && b1) {  // Third button: but1
    count = 3;
    delay(200);
  }
  else if (count == 3 && b3) {  // Fourth button: but3
    count = 4;
    delay(200);
  }
  else if ((b0 || b1 || b2 || b3) && count != 0) {  // If wrong button pressed out of sequence
    count = 0;
    digitalWrite(red, HIGH);  // Flash red LED for error
    delay(500);
    digitalWrite(red, LOW);
  }

  // If correct passcode entered
  if (count == 4) {
    digitalWrite(green, HIGH);  // Flash green LED for success
    delay(1000);
    digitalWrite(green, LOW);
    count = 0;  // Reset for the next attempt
  }

  delay(10); // Short delay to stabilize button readings
}
