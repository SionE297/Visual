#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Encoder.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define PIN_DT  2  // Connect to CLK
#define PIN_CLK 3  // Connect to DT
#define PIN_SW  4  // Connect to SW (button)
#define SIDE_SW 12
#define RED_LED_PIN 6
// Create a RotaryEncoder instance
Encoder encoder(PIN_CLK, PIN_DT);
#define NUMBER_of_OPTIONS 8 //Number of items in list

void setup() {
  pinMode(PIN_SW, INPUT_PULLUP); // Button connected with pull-up
  pinMode(SIDE_SW, INPUT_PULLUP); // Button connected with pull-up
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);                 // Same as "while(true);"
  }
  display.clearDisplay();
  display.display();
  Serial.begin(9600);

  setVeryDim();

  bool lockScreen=true;
  //Lock_Screen();    //skip this for now
} //setup end

void setVeryDim() {
  // 1) Contrast register — leave at a non‑zero value so text is still visible
  display.ssd1306_command(SSD1306_SETCONTRAST);  // 0x81
  display.ssd1306_command(0x02);                 // 0x01 was ok; 0x02 keeps a little headroom

  // 2) Pre‑charge period — command 0xD9
  display.ssd1306_command(0xD9);
  display.ssd1306_command(0x11);  // Phase 1 = 1 DCLK, Phase 2 = 1 DCLK  (0xXY: X=phase2, Y=phase1)
}

void loop() {
  display.clearDisplay();
  display.drawRoundRect(0, 16, 60, 10, 1, SSD1306_WHITE);
  display.drawRoundRect(0, 27, 60, 10, 2, SSD1306_WHITE);
  display.drawRoundRect(0, 38, 60, 10, 3, SSD1306_WHITE);
  display.drawRoundRect(0, 49, 60, 10, 4, SSD1306_WHITE);
  display.drawRoundRect(64, 16, 60, 10, 5, SSD1306_WHITE);
  display.drawRoundRect(64, 27, 60, 10, 6, SSD1306_WHITE);
  display.drawRoundRect(64, 38, 60, 10, 7, SSD1306_WHITE);
  display.drawRoundRect(64, 49, 60, 10, 8, SSD1306_WHITE);
  //display.drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color)
  display.display();
  delay(10000000);
}