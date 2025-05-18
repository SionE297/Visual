int cap1;
int cap2;
int enable1=3;
//int enable2=4;
int readPin1=A0;
int readPin2=A1;
int ledPin=13;
int swPin=2;

void setup() {
  // put your setup code here, to run once:
pinMode(enable1,OUTPUT);
//pinMode(enable2,OUTPUT);
pinMode(ledPin,OUTPUT);
pinMode(swPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
cap1 = analogRead(readPin1);
Serial.println(cap1);
delay(50);
if (cap1>0) {
  digitalWrite(ledPin,HIGH);
  }
else {
  digitalWrite(ledPin,LOW);
  }
}
