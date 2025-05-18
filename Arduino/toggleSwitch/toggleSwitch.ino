int readingPin=A5;
int V;
int printDelay=10;
bool on=false;
bool lock;
int mode=1;

void setup() {
  // put your setup code here, to run once:
  pinMode(readingPin,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  V=digitalRead(readingPin);
  Serial.println(V);
  delay(printDelay);
  if (V == mode) {
    
    if (on==false && lock==false) {
    digitalWrite(13,HIGH);
    on=true;
    lock=true;
    }
    else if (on==true && lock==false) {
    digitalWrite(13,LOW);
    on=false;
    lock=true;
    }
  }
  if (V != mode) {
    lock=false;
    
  }
}