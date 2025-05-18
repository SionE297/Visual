int xPin = A0;
int yPin = A2;
int swPin = A4;


void setup() {
  // put your setup code here, to run once:
pinMode(xPin,INPUT);
pinMode(yPin,INPUT);
pinMode(swPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
xPin=analogRead(xPin);
yPin=analogRead(yPin);

Serial.print("X:");
Serial.print(xPin);
Serial.print("    ");
Serial.print("Y:");
Serial.print(yPin);
Serial.println("    ");
delay(100);
}
