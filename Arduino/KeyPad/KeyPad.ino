




void setup() {
  for (uint8_t i=1; i<=9; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  Serial.begin(9600);
};

void loop() {
  Serial.print(digitalRead(2));
  Serial.print("    ");
  Serial.print(digitalRead(3));
  Serial.print("    ");
  Serial.print(digitalRead(4));
  Serial.print("    ");
  Serial.print(digitalRead(5));
  Serial.print("    ");
  Serial.print(digitalRead(6));
  Serial.print("    ");
  Serial.print(digitalRead(7));
  Serial.print("    ");
  Serial.print(digitalRead(8));
  Serial.print("    ");
  Serial.print(digitalRead(9));
  Serial.println();







};
