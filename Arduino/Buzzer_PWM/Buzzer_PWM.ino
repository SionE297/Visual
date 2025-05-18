int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 3;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int roundUp;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  roundUp=sensorValue/2.55;
  if (roundUp>255) {roundUp=255;}
  analogWrite(3, roundUp);
  analogWrite(5, roundUp);
  Serial.println(roundUp);
  //delay(10);

}
