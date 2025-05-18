int readPin1 = 8;
int readPin2 = 9;
int output1 = 13;
int input1;
int input2;

void setup() {
  // put your setup code here, to run once:
  pinMode(output1,OUTPUT);
  pinMode(readPin1,INPUT);
  pinMode(readPin2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  input1=digitalRead(readPin1);
  input2=digitalRead(readPin2);
  
  if (input1==true && input2 ==true) {
  digitalWrite(output1,HIGH);
  } 
  else {
  digitalWrite(output1,LOW);
  }
  delay(10);

}
