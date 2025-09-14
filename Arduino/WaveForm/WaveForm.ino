#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C   // most 128x64 OLEDs use 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define inputPin A0

int arr[SCREEN_WIDTH] = {0}; // store waveform samples

void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
}

void loop() {
  // Shift old values left
  for (int i = 0; i < SCREEN_WIDTH - 1; i++) {
    arr[i] = arr[i + 1];
  }

  // Read input voltage
  int raw = analogRead(inputPin);
  float voltage = raw * (5.0 / 1023.0); // convert to voltage
  int y = SCREEN_HEIGHT - map(raw, 0, 1023, 0, SCREEN_HEIGHT - 1); // invert for oscilloscope look
  arr[SCREEN_WIDTH - 1] = y;

  // Clear screen
  display.clearDisplay();

  // Draw voltage text
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(voltage, 1); // 1 decimal place
  display.print("V");

  // Draw waveform as connected lines
  for (int i = 1; i < SCREEN_WIDTH; i++) {
    display.drawLine(i - 1, arr[i - 1], i, arr[i], SSD1306_WHITE);
  }

  // Show it
  display.display();

  //delay(50); // adjust speed
}

