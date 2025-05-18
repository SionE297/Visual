int readingPin=A5;
int V;
int printDelay=100;

void setup() {
  // put your setup code here, to run once:
  pinMode(readingPin,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  pinMode(2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  V=analogRead(readingPin);
  Serial.println(V);
  delay(printDelay);

  if (V < 10) {
    digitalWrite(2,HIGH);
  }
  else {
    digitalWrite(2,LOW);
  }
  delay(100);
}
