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
// Create a RotaryEncoder instance
Encoder encoder(PIN_CLK, PIN_DT);

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

} //setup end






void loop() {
  // put your main code here, to run repeatedly:

}
