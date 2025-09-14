int pinX=A0;
int pinY=A1;
int ledTop=5;
int ledRight=11;
int ledBottom=10;
int ledLeft=3;

void setup() {
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(ledTop, OUTPUT);
  pinMode(ledRight, OUTPUT);
  pinMode(ledBottom, OUTPUT);
  pinMode(ledLeft, OUTPUT);
  Serial.begin(9600);
}

  int x;
  int y;
  int rawX;
  int rawY;

void loop() {
  rawX = analogRead(pinX);
  rawY = analogRead(pinY);
  x = rawX -511 ;
  y = rawY -505 ;

  Serial.print("X: ");
  Serial.print(x);
  Serial.print("      ");
  Serial.print("Y: ");
  Serial.println(y);

  if (x<-10) {
    analogWrite(ledTop, (abs(x) /4));
    digitalWrite(ledBottom, LOW);
  }
  else if (x>10) {
    analogWrite(ledBottom, (x/4));
    digitalWrite(ledTop, LOW);
  }
  if (y<-10) {
    analogWrite(ledRight, (abs(y) /4));
    digitalWrite(ledLeft, LOW);
  }
  else if (y>10) {
    analogWrite(ledLeft, (y/4));
    digitalWrite(ledRight, LOW);
  }
  if (x >-10 && x<10) {
    digitalWrite(ledTop, LOW);
    digitalWrite(ledBottom, LOW);
  }
  if (y >-10 && y<10) {
    digitalWrite(ledRight, LOW);
    digitalWrite(ledLeft, LOW);
  }


}
