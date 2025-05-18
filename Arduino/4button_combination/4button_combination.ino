int but0=2;
int but1=4;
int but2=6;
int but3=8;
int green=13;
int red=12;
int count=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(but0, INPUT); // Configure buttons with internal pull-up resistors
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
but0=digitalRead(2);
but1=digitalRead(4);
but2=digitalRead(6);
but3=digitalRead(8);
  Serial.print("but0=");
  Serial.print(but0);
  Serial.print("  but1=");
  Serial.print(but1);
  Serial.print("  but2=");
  Serial.print(but2);
  Serial.print("  but3=");
  Serial.print(but3);
  Serial.print("  count=");
  Serial.println(count);

if (count==0 && but2 != 1) {count=0;}
else if (count==0 && but2 == 1) {count=1;}
if (count==1 && but0 != 1) {count=0;}
else if (count==1 && but0 == 1) {count=2;}
if (count==2 && but1 != 1) {count=0;}
else if (count==2 && but1 == 1) {count=3;}
if (count==3 && but3 != 1) {count=0;}
else if (count==3 && but3 == 1) {count=4;}

if (but0 && but1 && but2 && but3) {count==0;}
if (count==4 && (but0 && but1 && but2 && but3) != 1) {
  digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(green,LOW);
  count=0;
}
delay(10);
}

