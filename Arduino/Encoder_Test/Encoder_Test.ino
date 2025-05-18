#include <Encoder.h>

Encoder myEnc(2, 3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  static long lastPos = 0;
  long pos = myEnc.read();

  if (pos != lastPos) {  
    Serial.println(pos);
    lastPos = pos;
  }
}
