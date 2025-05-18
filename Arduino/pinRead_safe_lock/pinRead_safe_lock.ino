int readingPin1=A0;
int V1;
int printDelay=0;
int readingPin2=A1;
int V2;

void setup() {
  // put your setup code here, to run once:
  pinMode(readingPin1,INPUT);
  pinMode(readingPin2,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  V1=analogRead(readingPin1);
  Serial.println(V1);
  delay(printDelay);
  if (V1 > 500 && V1 < 550) {
    digitalWrite(13,HIGH);
  }
  else {
    digitalWrite(13,LOW);
  }
  V2=analogRead(readingPin2);
  Serial.println(V2);
  delay(printDelay);
  if (V2 > 300 && V2 < 350) {
    digitalWrite(12,HIGH);
  }
  else {
    digitalWrite(12,LOW);
  }
}
