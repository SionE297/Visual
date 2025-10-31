#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(13);  // attaches the servo on pin 9 to the servo object
  pinMode(A1, INPUT);
  Serial.begin(9600);
}
int pos;

void loop() {
  pos = map(analogRead(A1),0, 940, 0, 200);
  Serial.println(pos);
  myservo.write(pos);

  

}