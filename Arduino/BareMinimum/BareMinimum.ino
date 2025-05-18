int pin=11;
int value=200;


void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pin,value);

}
