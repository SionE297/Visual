int readingPin=A5;
int V;
int printDelay=100;
bool on=false;

void setup() {
  // put your setup code here, to run once:
  pinMode(readingPin,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  V=analogRead(readingPin);
  Serial.println(V);
  delay(printDelay);
  if (V < 1 && on==false) {
    digitalWrite(13,HIGH);
    on=true;
    }
  else if (V < 1 && on==true) {
    digitalWrite(13,LOW);
    on=false;
  }
  delay(100);
}
