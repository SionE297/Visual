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

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(38, 22);
  display.println(0);
  display.setCursor(58, 22);
  display.println(0);
  display.setCursor(78, 22);
  display.println(0);

  setVeryDim();

  bool lockScreen=true;
  //Lock_Screen();    //skip this for now
} //setup end

const unsigned char battery4[] PROGMEM = { 
  0x7f, 0xfc, 0x80, 0x02, 0xb6, 0xdb, 0xb6, 0xdb, 0xb6, 0xdb, 0xb6, 0xdb, 0x80, 0x02, 0x7f, 0xfc};
  const unsigned char battery3[] PROGMEM = {
	0x7f, 0xfc, 0x80, 0x02, 0xb6, 0xc3, 0xb6, 0xc3, 0xb6, 0xc3, 0xb6, 0xc3, 0x80, 0x02, 0x7f, 0xfc};
  const unsigned char battery2[] PROGMEM = {
	0x7f, 0xfc, 0x80, 0x02, 0xb6, 0x03, 0xb6, 0x03, 0xb6, 0x03, 0xb6, 0x03, 0x80, 0x02, 0x7f, 0xfc, };
  const unsigned char battery1[] PROGMEM = {
	0x7f, 0xfc, 0x80, 0x02, 0xb0, 0x03, 0xb0, 0x03, 0xb0, 0x03, 0xb0, 0x03, 0x80, 0x02, 0x7f, 0xfc,};
  const unsigned char battery0[] PROGMEM = {
	0x7f, 0xfc, 0x80, 0x02, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x02, 0x7f, 0xfc};
  const unsigned char selectBox [] PROGMEM = {
	// image 111x16px
	0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x40, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x06, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8};
  const unsigned char smallBox [] PROGMEM = {
	// image_2025-05-30_150722503, 57x16px
	0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00};
  const unsigned char smallBoxSelect [] PROGMEM = {
	// image_2025-05-31_133956954, 57x16px
	0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00};
  const unsigned char signal [] PROGMEM = {
	// 'image_2025-05-31_194247242, 32x24px
	0x06, 0x00, 0x00, 0x60, 0x0e, 0x00, 0x00, 0x70, 0x1e, 0x00, 0x00, 0x78, 0x3e, 0x00, 0x00, 0x7c, 
	0x3c, 0x00, 0x00, 0x3c, 0x78, 0x70, 0x0e, 0x1e, 0x78, 0xf0, 0x0f, 0x1e, 0x70, 0xf0, 0x0f, 0x0e, 
	0xf1, 0xe0, 0x07, 0x8f, 0xf1, 0xc0, 0x03, 0x8f, 0xe1, 0xc3, 0xc3, 0x87, 0xe3, 0xc3, 0xc3, 0xc7, 
	0xe3, 0xc3, 0xc3, 0xc7, 0xe1, 0xc3, 0xc3, 0x87, 0xf1, 0xc0, 0x03, 0x8f, 0xf1, 0xe0, 0x07, 0x8f, 
	0x70, 0xf0, 0x0f, 0x0e, 0x78, 0xf0, 0x0f, 0x1e, 0x78, 0x70, 0x0e, 0x1e, 0x3c, 0x00, 0x00, 0x3c, 
	0x3e, 0x00, 0x00, 0x7c, 0x1e, 0x00, 0x00, 0x78, 0x0e, 0x00, 0x00, 0x70, 0x06, 0x00, 0x00, 0x60};
  const unsigned char checkbox_selected [] PROGMEM = {
	// 'image_2025-07-30_123800026, 7x7px
	0xfe, 0x82, 0xba, 0xba, 0xba, 0x82, 0xfe};
  const unsigned char checkbox_unselected [] PROGMEM = {
	// 'image_2025-07-30_124254327, 7x7px
	0xfe, 0x82, 0x82, 0x82, 0x82, 0x82, 0xfe};
  const unsigned char radio_selected [] PROGMEM = {
	// 'image_2025-08-16_211215942, 7x7px
	0x7c, 0x82, 0xba, 0xba, 0xba, 0x82, 0x7c};
  const unsigned char radio_unselected [] PROGMEM = {
	// 'image_2025-08-16_211028522, 7x7px
	0x7c, 0x82, 0x82, 0x82, 0x82, 0x82, 0x7c};
  const unsigned char selectArrow [] PROGMEM = {
	// 'image_2025-08-16_200915587, 4x7px
	0x80, 0x40, 0x20, 0x10, 0x20, 0x40, 0x80};
  const unsigned char selectArrowBold [] PROGMEM = {
	// 'image_2025-08-16_202849121, 4x7px
	0x80, 0xc0, 0x60, 0x30, 0x60, 0xc0, 0x80};
  const unsigned char pointArrow [] PROGMEM = {
	// 'image_2025-08-16_211616936, 8x5px
	0x0c, 0x06, 0xff, 0x06, 0x0c};
  const unsigned char keyboardUppercase [] PROGMEM = {
	// 'image_2025-08-27_124757198, 128x37px
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x01, 
	0x80, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x01, 
	0x80, 0x02, 0x38, 0x91, 0x27, 0xc9, 0xe2, 0x7c, 0x91, 0x24, 0x48, 0xe2, 0x38, 0x9e, 0x20, 0x01, 
	0x84, 0x02, 0x44, 0x91, 0x24, 0x09, 0x12, 0x54, 0x91, 0x24, 0x48, 0x42, 0x44, 0x91, 0x21, 0x81, 
	0x82, 0x02, 0x44, 0x91, 0x24, 0x09, 0x12, 0x10, 0x8a, 0x24, 0x48, 0x42, 0x44, 0x91, 0x23, 0x01, 
	0x81, 0x02, 0x44, 0x95, 0x27, 0x89, 0xe2, 0x10, 0x84, 0x24, 0x48, 0x42, 0x44, 0x9e, 0x27, 0xf9, 
	0x82, 0x02, 0x54, 0x95, 0x24, 0x09, 0x42, 0x10, 0x84, 0x24, 0x48, 0x42, 0x44, 0x90, 0x23, 0x01, 
	0x84, 0xe2, 0x48, 0x95, 0x24, 0x09, 0x22, 0x10, 0x84, 0x24, 0x48, 0x42, 0x44, 0x90, 0x21, 0x81, 
	0x80, 0x02, 0x34, 0x8a, 0x27, 0xc9, 0x12, 0x10, 0x84, 0x23, 0x88, 0xe2, 0x38, 0x90, 0x20, 0x01, 
	0x80, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x01, 
	0x80, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x00, 0x01, 
	0x80, 0x00, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x00, 0x01, 
	0x80, 0x40, 0x21, 0x08, 0xe2, 0x78, 0x9f, 0x23, 0xc9, 0x12, 0x1c, 0x91, 0x24, 0x08, 0x00, 0x01, 
	0x80, 0xe0, 0x22, 0x89, 0x12, 0x44, 0x90, 0x24, 0x49, 0x12, 0x08, 0x92, 0x24, 0x08, 0x30, 0x11, 
	0x81, 0xf0, 0x24, 0x49, 0x02, 0x44, 0x90, 0x24, 0x09, 0x12, 0x08, 0x94, 0x24, 0x08, 0x60, 0x11, 
	0x81, 0x50, 0x24, 0x48, 0xe2, 0x44, 0x9e, 0x24, 0x09, 0xf2, 0x08, 0x98, 0x24, 0x08, 0xff, 0xe1, 
	0x80, 0x40, 0x27, 0xc8, 0x12, 0x44, 0x90, 0x24, 0xc9, 0x12, 0x08, 0x94, 0x24, 0x08, 0x60, 0x01, 
	0x80, 0x40, 0x24, 0x49, 0x12, 0x44, 0x90, 0x24, 0x49, 0x12, 0x48, 0x92, 0x24, 0x08, 0x30, 0x01, 
	0x80, 0x40, 0x24, 0x48, 0xe2, 0x78, 0x90, 0x23, 0xc9, 0x12, 0x30, 0x91, 0x27, 0xc8, 0x00, 0x01, 
	0x80, 0x00, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x00, 0x01, 
	0x80, 0x00, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x04, 0x02, 0x00, 0x01, 
	0x80, 0x00, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x04, 0x02, 0x00, 0x01, 
	0x88, 0x73, 0xe2, 0x7c, 0x91, 0x23, 0x89, 0x12, 0x78, 0x91, 0x24, 0x48, 0x04, 0x02, 0x11, 0x01, 
	0x98, 0x88, 0x22, 0x04, 0x91, 0x24, 0x49, 0x12, 0x44, 0x91, 0x26, 0xc8, 0x04, 0x02, 0x08, 0x81, 
	0x88, 0x08, 0x42, 0x08, 0x8a, 0x24, 0x09, 0x12, 0x44, 0x99, 0x25, 0x48, 0x04, 0x02, 0x04, 0x41, 
	0x88, 0x70, 0xc2, 0x38, 0x84, 0x24, 0x09, 0x12, 0x78, 0x95, 0x25, 0x48, 0x04, 0x02, 0x02, 0x21, 
	0x88, 0x80, 0x22, 0x20, 0x8a, 0x24, 0x09, 0x12, 0x44, 0x93, 0x25, 0x48, 0xc4, 0x62, 0x04, 0x41, 
	0x88, 0x82, 0x22, 0x40, 0x91, 0x24, 0x48, 0xa2, 0x44, 0x91, 0x24, 0x48, 0xc4, 0x62, 0x08, 0x81, 
	0x9c, 0xf9, 0xca, 0x7c, 0x91, 0x23, 0x88, 0x42, 0x78, 0x91, 0x24, 0x48, 0x84, 0x02, 0x11, 0x01, 
	0x80, 0x00, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x09, 0x04, 0x02, 0x00, 0x01, 
	0x80, 0x00, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x04, 0x02, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  const unsigned char keyboardLowercase [] PROGMEM = {
	// 'image_2025-08-27_125028243, 128x37px
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x01, 
	0x80, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x01, 
	0x80, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x10, 0x80, 0x20, 0x08, 0x42, 0x00, 0x80, 0x20, 0x01, 
	0x84, 0x02, 0x34, 0x91, 0x23, 0x89, 0x62, 0x10, 0x91, 0x24, 0x48, 0x02, 0x38, 0x96, 0x21, 0x81, 
	0x82, 0x02, 0x4c, 0x91, 0x24, 0x49, 0x92, 0x7c, 0x91, 0x24, 0x48, 0xc2, 0x44, 0x99, 0x23, 0x01, 
	0x81, 0x02, 0x4c, 0x95, 0x27, 0xc9, 0x02, 0x10, 0x8f, 0x24, 0x48, 0x42, 0x44, 0x99, 0x27, 0xf9, 
	0x82, 0x02, 0x34, 0x95, 0x24, 0x09, 0x02, 0x10, 0x81, 0x24, 0xc8, 0x42, 0x44, 0x96, 0x23, 0x01, 
	0x84, 0xe2, 0x04, 0x8a, 0x23, 0x89, 0x02, 0x14, 0x91, 0x23, 0x48, 0x42, 0x38, 0x90, 0x21, 0x81, 
	0x80, 0x02, 0x04, 0x80, 0x20, 0x08, 0x02, 0x08, 0x8e, 0x20, 0x08, 0xe2, 0x00, 0x90, 0x20, 0x01, 
	0x80, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x01, 
	0x80, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x00, 0x01, 
	0x80, 0x00, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x00, 0x01, 
	0x80, 0x40, 0x20, 0x08, 0x02, 0x04, 0x84, 0x20, 0x09, 0x02, 0x08, 0x90, 0x23, 0x08, 0x00, 0x01, 
	0x80, 0xe0, 0x23, 0x08, 0xf2, 0x04, 0x8a, 0x23, 0x89, 0x02, 0x00, 0x90, 0x21, 0x08, 0x30, 0x11, 
	0x81, 0xf0, 0x20, 0x89, 0x02, 0x34, 0x88, 0x24, 0xc9, 0x62, 0x08, 0x92, 0x21, 0x08, 0x60, 0x11, 
	0x81, 0x50, 0x23, 0x88, 0xe2, 0x4c, 0x9c, 0x24, 0xc9, 0x92, 0x08, 0x94, 0x21, 0x08, 0xff, 0xe1, 
	0x80, 0x40, 0x24, 0x88, 0x12, 0x44, 0x88, 0x23, 0x49, 0x12, 0x08, 0x98, 0x21, 0x08, 0x60, 0x01, 
	0x80, 0x40, 0x23, 0xc9, 0xe2, 0x4c, 0x88, 0x20, 0x49, 0x12, 0x48, 0x94, 0x21, 0x08, 0x30, 0x01, 
	0x80, 0x40, 0x20, 0x08, 0x02, 0x34, 0x88, 0x23, 0x89, 0x12, 0x30, 0x92, 0x23, 0x88, 0x00, 0x01, 
	0x80, 0x00, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x00, 0x01, 
	0x80, 0x00, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x04, 0x02, 0x00, 0x01, 
	0x80, 0x00, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x04, 0x02, 0x00, 0x01, 
	0x88, 0x73, 0xe2, 0x00, 0x80, 0x20, 0x08, 0x02, 0x40, 0x80, 0x20, 0x08, 0x04, 0x02, 0x11, 0x01, 
	0x98, 0x88, 0x22, 0x7c, 0x91, 0x23, 0x89, 0x12, 0x40, 0x80, 0x20, 0x08, 0x04, 0x02, 0x08, 0x81, 
	0x88, 0x08, 0x42, 0x08, 0x8a, 0x24, 0x49, 0x12, 0x58, 0x96, 0x26, 0x88, 0x04, 0x02, 0x04, 0x41, 
	0x88, 0x70, 0xc2, 0x10, 0x84, 0x24, 0x09, 0x12, 0x64, 0x99, 0x25, 0x48, 0x04, 0x02, 0x02, 0x21, 
	0x88, 0x80, 0x22, 0x20, 0x8a, 0x24, 0x48, 0xa2, 0x44, 0x91, 0x25, 0x48, 0xc4, 0x62, 0x04, 0x41, 
	0x88, 0x82, 0x22, 0x7c, 0x91, 0x23, 0x88, 0x42, 0x64, 0x91, 0x25, 0x48, 0xc4, 0x62, 0x08, 0x81, 
	0x9c, 0xf9, 0xca, 0x00, 0x80, 0x20, 0x08, 0x02, 0x58, 0x91, 0x25, 0x48, 0x84, 0x02, 0x11, 0x01, 
	0x80, 0x00, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x09, 0x04, 0x02, 0x00, 0x01, 
	0x80, 0x00, 0x02, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x20, 0x08, 0x04, 0x02, 0x00, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  const unsigned char commandLogo [] PROGMEM = {
	// 'image_2025-08-27_141226131, 6x5px
	0x80, 0x40, 0x20, 0x40, 0x9c};
  const unsigned char backspaceLogo [] PROGMEM = {
	// 'image_2025-08-27_145534956, 8x5px
	0x30, 0x60, 0xff, 0x60, 0x30};
  const unsigned char shiftLogo [] PROGMEM = {
	// 'image_2025-08-27_150926384, 5x7px
	0x20, 0x70, 0xf8, 0xa8, 0x20, 0x20, 0x20};
  const unsigned char enterLogo [] PROGMEM = {
	// 'image_2025-08-27_152515841, 12x5px
	0x30, 0x10, 0x60, 0x10, 0xff, 0xe0, 0x60, 0x00, 0x30, 0x00};
  const unsigned char numbersLogo [] PROGMEM = {
	// 'image_2025-08-27_152954119, 18x7px
	0x43, 0x9f, 0x00, 0xc4, 0x41, 0x00, 0x40, 0x42, 0x00, 0x43, 0x86, 0x00, 0x44, 0x01, 0x00, 0x44, 
	0x11, 0x00, 0xe7, 0xce, 0x40};
  const unsigned char spaceLogo [] PROGMEM = {
	// 'image_2025-08-28_124343696, 8x2px
	0x81, 0xff};


/*class led {
  private:
    int pin;
    unsigned long interval, duration, startTime, lastToggle;
    bool running, state;

  public:
    led(int p) : pin(p), running(false), state(LOW) {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
    }

    // kick off a blink cycle
    void blink(unsigned long blinkInterval, unsigned long totalDuration) {
      interval   = blinkInterval;
      duration   = totalDuration;
      startTime  = lastToggle = millis();
      state      = LOW;
      running    = true;
      digitalWrite(pin, state);
    }

    void light(int lightDuration) {
      static int lightDurationGlobal = lightDuration;
      int now = millis();
      digitalWrite(pin, HIGH);
      
    }//light
};//class

led redLED(RED_LED_PIN);*/

bool EncoderSW=false;
bool SideSW=false;
void buttons() {
  if (digitalRead(SIDE_SW) == LOW) {SideSW=true;}
  else {SideSW=false;}
  if (digitalRead(PIN_SW) == LOW) {EncoderSW=true;}
  else {EncoderSW=false;}};
void battery_scroll() {
  static unsigned long lastUpdate = 0;
  const unsigned long updateInterval = 500;

  static int batteryLevel = 0;
  const unsigned char* batteryIcons[] = { battery0, battery1, battery2, battery3, battery4 };

  if (millis() - lastUpdate >= updateInterval) {
    display.fillRect(112, 0, 16, 8, BLACK);
    display.drawBitmap(112, 0, batteryIcons[batteryLevel], 16, 8, WHITE);
    display.display();

    batteryLevel = (batteryLevel + 1) % 5;
    lastUpdate = millis();
    }
  };
/*void updateDisplayNumber(int value) {
  display.fillRect(0, 0, 30, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(value);
  display.display();
  }*/
int newPosition = 0;
int lastPosition = -999;
int encoderOffset = 0;
const char* Options[] = {"IR-Remote", "USB-hak5", "Radio", "Timer", "Serial", "Lock Screen", "External", "Settings"};
char* currentSelected = Options[0];   //0 to start at settings
bool isHome = true;
int taskNum;
void rotary_encoder() {
  newPosition = (encoder.read() / 2) - encoderOffset; // Adjust "/2" based on your encoder's resolution
  
  if (lastPosition != newPosition) {   // Update display if position changes
    int newSelectedIndex = (newPosition % NUMBER_of_OPTIONS + NUMBER_of_OPTIONS) % NUMBER_of_OPTIONS;  // Keep index within bounds of task options
    taskNum=newSelectedIndex;
    if (isHome) {
      updateMenu(newSelectedIndex);
    }
    lastPosition = newPosition;
    
    currentSelected = Options[newSelectedIndex]; // Update selection
    //updateDisplayNumber(newPosition);
  }
  buttons();  // Check if the button is pressed to toggle home/menu view
};
void setZero() {
  encoderOffset = encoder.read() / 2;
  lastPosition = 0;
  newPosition = 0;

};
void setVeryDim() {
  // 1) Contrast register — leave at a non‑zero value so text is still visible
  display.ssd1306_command(SSD1306_SETCONTRAST);  // 0x81
  display.ssd1306_command(0x02);                 // 0x01 was ok; 0x02 keeps a little headroom

  // 2) Pre‑charge period — command 0xD9
  display.ssd1306_command(0xD9);
  display.ssd1306_command(0x11);  // Phase 1 = 1 DCLK, Phase 2 = 1 DCLK  (0xXY: X=phase2, Y=phase1)
}
void debounce(bool * whichButton) {
  while (true) {
    buttons();
    if (!(*whichButton)) {break;}
  }
};
void updateMenu(int selectedIndex) {
  display.fillRect(0, 16, 128, 48, SSD1306_BLACK);                   // Clear menu section
  display.drawBitmap(5, 31, selectBox, 111, 16, SSD1306_WHITE);
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  // Display previous and next options (with wrap-around)
  display.setCursor(20, 35);
  display.println(Options[selectedIndex]);
  display.setCursor(20, 17);
  display.println(Options[(selectedIndex + (NUMBER_of_OPTIONS-1) ) % NUMBER_of_OPTIONS]); // Previous
  display.setCursor(20, 53);
  display.println(Options[(selectedIndex + 1) % NUMBER_of_OPTIONS]); // Next
  display.display();
};
void time(const char* time) {
  if (isHome) {
    display.fillRect(0, 0, 58, 15, BLACK);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(2, 0);
    display.println(time);
    display.display();
  }
};
bool lockScreen=true;
int selectedDigit=0;
int pasNum1=2;
int pasNum2=9;
int pasNum3=7;
void password() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(38, 22);
  display.println(0);
  display.setCursor(58, 22);
  display.println(0);
  display.setCursor(78, 22);
  display.println(0);
  display.display();
  int firstNum=0;
  int secondNum=0;
  int thirdNum=0;
  selectedDigit=0;
  while (lockScreen) {
    
    buttons();
    newPosition = (encoder.read() / 2) - encoderOffset;
    lastPosition = newPosition;
    int numb = (newPosition % 10 + 10) % 10;  // Ensure positive modulo result
    if (EncoderSW) {
      selectedDigit = (selectedDigit+1) % 3;
      debounce(&EncoderSW);
    }
    if (SideSW) {
      selectedDigit = (selectedDigit+1) % 3;
      debounce(&SideSW);
    }
    /*if (SideSW) {
      Lock_Screen();
      break;
    }*/
    if (selectedDigit==0) {
      display.fillRect(38, 0, 10, 64, SSD1306_BLACK);
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(38, 22);
      display.println(numb);
      firstNum=numb;
      display.display();
    }
    if (selectedDigit==1) {
      display.fillRect(58, 0, 10, 64, SSD1306_BLACK);
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(58, 22);
      display.println(numb);
      secondNum=numb;
      display.display();
    }
    if (selectedDigit==2) {
      display.fillRect(78, 0, 10, 64, SSD1306_BLACK);
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(78, 22);
      display.println(numb);
      thirdNum=numb;
      display.display();
    }
    buttons();
    if (firstNum==pasNum1 && secondNum==pasNum2 && thirdNum==pasNum3 && (EncoderSW || SideSW)){
    lockScreen=false;
    setZero();
    isHome=true;
    updateMenu(newPosition % NUMBER_of_OPTIONS);
    break;
    }
  }   //lockScreen loop end
  if (SideSW) {
  debounce(&SideSW);
  } else if (EncoderSW) {
  debounce(&EncoderSW);
  }

};
void Task() { 
  if (taskNum==0 && EncoderSW==true && isHome) {
    isHome=false;
    //Remote();
    Empty();
    updateMenu(0);}
  else if (taskNum==1 && EncoderSW==true && isHome) {
    isHome=false;
    usbHak5();
    updateMenu(1);}
  else if (taskNum==2 && EncoderSW==true && isHome) {
    isHome=false;
    Radio();
    updateMenu(2);}
  else if (taskNum==3 && EncoderSW==true && isHome) {
    isHome=false;
    Timer();
    updateMenu(3);}
  else if (taskNum==4 && EncoderSW==true && isHome) {
    isHome=false;
    SerialCom();
    //testdrawchar();
    updateMenu(4);}
  else if (taskNum==5 && EncoderSW==true && isHome) {
    isHome=false;
    Lock_Screen();}
  else if (taskNum==6 && EncoderSW==true && isHome) {
    isHome=false;
    External();
    updateMenu(6);}
  else if (taskNum==7 && EncoderSW==true && isHome) {
    isHome=false;
    Settings();
    updateMenu(7);}
};
void Radio() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Radio"));
  while (true) {
    battery_scroll();
    time("12:36");
    display.display();
    buttons();
    if (SideSW) {
      setZero();
      display.clearDisplay();
      isHome=true;
      return;
    }
  }//while
};
bool lockScreenOnStart=false;     //lkScr_Start
bool SettingsOptionsValue[4] {false, false, false, false};
void Settings() {
  isHome=false;
  debounce(&EncoderSW);
  setZero(); 
  int SettingsOption=0;
  int SettingsEncoder=0;

  while (true) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(16, 0);
    display.print(F("Settings"));

    //display.drawBitmap(0, 18, selectArrowBold, 4, 7, SSD1306_WHITE);
    //display.drawBitmap(0, 30, selectArrow, 4, 7, SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(6, 18);
    display.println(F("Brightness"));
    display.setCursor(6, 30);
    display.println(F("Enable Lock"));
    display.setCursor(6, 42);
    display.println(F("Change Password"));
    display.setCursor(6, 54);
    display.println(F("Pixel Counter"));

    display.drawBitmap(119, 19, pointArrow, 8, 5, SSD1306_WHITE);
    display.drawBitmap(120, 30, radio_unselected, 7, 7, SSD1306_WHITE);
    display.drawBitmap(119, 43, pointArrow, 8, 5, SSD1306_WHITE);
    display.drawBitmap(119, 55, pointArrow, 8, 5, SSD1306_WHITE);

    rotary_encoder();
    
    if (newPosition > SettingsEncoder) {
      SettingsOption ++;
      if (SettingsOption > 3) {
        SettingsOption=3;
        }
      SettingsEncoder = newPosition;
    }
    else if (newPosition < SettingsEncoder) {
      SettingsOption --;
      if (SettingsOption < 0) {
      SettingsOption=0;
      }
      SettingsEncoder = newPosition;
    }
    
    // Clear old lines
    display.fillRect(0, 18, 4, 46, SSD1306_BLACK);
    // Draw new arrow at SettingsOption
    int y = 18 + SettingsOption * 12;
    display.drawBitmap(0, y, selectArrowBold, 4, 7, SSD1306_WHITE);

    if (EncoderSW) {
      SettingsOptionsValue[SettingsOption] = !SettingsOptionsValue[SettingsOption];
      debounce(&EncoderSW);
    }

    if (SideSW) {
      isHome=true;
      setZero();
      debounce(&SideSW);
      display.clearDisplay();
      return;
    }

    if (SettingsOptionsValue[0]==true) {
      brightnessControll();
    }
    if (SettingsOptionsValue[1]==true) {
    }
    if (SettingsOptionsValue[2]==true) {
    }
    if (SettingsOptionsValue[3]==true) {
      counter();
    }

    display.display();
  } //while 1
};
void brightnessControll() {
  setZero();
  int brightnessEncoder = 0;    // tracks rotary
  int brightnessPercentage = 1; // 1–25
  int brightnessLevel = 0;      // 0–255

  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  setZero();
  
  while (true) {
    rotary_encoder();

    if (newPosition > brightnessEncoder) {
      brightnessPercentage ++;
      if (brightnessPercentage > 21) {
        brightnessPercentage = 21;
      }
      brightnessEncoder = newPosition;
    }
    else if (newPosition < brightnessEncoder) {
      brightnessPercentage --;
      if (brightnessPercentage < 1) {
        brightnessPercentage = 1;
      }
      brightnessEncoder = newPosition;
    }
    
    if (brightnessPercentage >= 1 && brightnessPercentage <= 21) {  //if statement not needed
      brightnessLevel = map(brightnessPercentage, 1, 21, 1, 255);
      display.ssd1306_command(SSD1306_SETCONTRAST);
      display.ssd1306_command(brightnessLevel);
    
      //percentage number
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      if (brightnessPercentage >= 1 && brightnessPercentage <= 20) {
        display.setCursor(114, 48);
        display.println(brightnessPercentage);
      }
      else if (brightnessPercentage == 21) {
        display.setCursor(110, 48);
        display.println(F("MAX"));
      }

      display.fillRoundRect(11, 21, brightnessPercentage * 5, 20, 4, SSD1306_WHITE);
      display.drawRoundRect(8, 18, 111, 26, 5, SSD1306_WHITE);
      display.display();
    }

    if (SideSW) {
      debounce(&SideSW); 
      setZero();
      SettingsOptionsValue[0]=false; 
      return;
    }

  }//while
};
void counter() {
  int count=0;
  isHome=false;
  display.clearDisplay();
  display.display();
  debounce(&EncoderSW);

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(100, 0);
  display.println(count);
  display.display();

  while (true) {
    buttons();
    if (EncoderSW) {
      debounce(&EncoderSW);
      SettingsOptionsValue[3] = false;
      return;
    }
    if (SideSW) {
      display.drawPixel(count, count, SSD1306_WHITE);
      count++;
      display.fillRect(100, 0, 28, 16, SSD1306_BLACK);
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(100, 0);
      display.println(count);
      display.display();
      debounce(&SideSW);
    }
  }
};
/*void Remote() {
  setZero();
  debounce(&EncoderSW);
  display.clearDisplay();
  
  while (true) {
    //redLED.update();
    rotary_encoder(); //buttons(); inside
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(4, 0);
    display.println(F("IR-Remote"));
    if (SideSW) {
      isHome=true;
      debounce(&SideSW);
      return;
      }
    switch (newPosition) {
      case 0:
          display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
          display.drawBitmap(3, 16, smallBoxSelect, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 16, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(3, 42, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 42, smallBox, 57, 16, SSD1306_WHITE);
          display.setTextSize(1);
          display.setTextColor(SSD1306_BLACK);
          display.setCursor(14, 20);
          display.println(F("S-Base"));
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(79, 20);
          display.println(F("Garage"));
          display.setCursor(13, 46);
          display.println(F("Door-3"));
          display.setCursor(82, 46);
          display.println(F("R2-D2"));
          break;
      case 1:
          display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
          display.drawBitmap(3, 16, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 16, smallBoxSelect, 57, 16, SSD1306_WHITE);
          display.drawBitmap(3, 42, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 42, smallBox, 57, 16, SSD1306_WHITE);
          display.setTextSize(1);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(14, 20);
          display.println(F("S-Base"));
          display.setTextColor(SSD1306_BLACK);
          display.setCursor(79, 20);
          display.println(F("Garage"));
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(13, 46);
          display.println(F("Door-3"));
          display.setCursor(82, 46);
          display.println(F("R2-D2"));
          break;
      case 2:
          display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
          display.drawBitmap(3, 16, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 16, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(3, 42, smallBoxSelect, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 42, smallBox, 57, 16, SSD1306_WHITE);
          display.setTextSize(1);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(14, 20);
          display.println(F("S-Base"));
          display.setCursor(79, 20);
          display.println(F("Garage"));
          display.setTextColor(SSD1306_BLACK);
          display.setCursor(13, 46);
          display.println(F("Door-3"));
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(82, 46);
          display.println(F("R2-D2"));
          break;
      case 3:
          display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
          display.drawBitmap(3, 16, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 16, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(3, 42, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 42, smallBoxSelect, 57, 16, SSD1306_WHITE);
          display.setTextSize(1);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(14, 20);
          display.println(F("S-Base"));
          display.setCursor(79, 20);
          display.println(F("Garage"));
          display.setCursor(13, 46);
          display.println(F("Door-3"));
          display.setTextColor(SSD1306_BLACK);
          display.setCursor(82, 46);
          display.println(F("R2-D2"));
          break;
      default:
          display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
          display.drawBitmap(3, 16, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 16, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(3, 42, smallBox, 57, 16, SSD1306_WHITE);
          display.drawBitmap(68, 42, smallBoxSelect, 57, 16, SSD1306_WHITE);
          display.setTextSize(1);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(14, 20);
          display.println(F("S-Base"));
          display.setCursor(79, 20);
          display.println(F("Garage"));
          display.setCursor(13, 46);
          display.println(F("Door-3"));
          display.setTextColor(SSD1306_BLACK);
          display.setCursor(82, 46);
          display.println(F("R2-D2"));
        break;
    }//switch
    
    if (EncoderSW) {
      switch (newPosition) {
        case 0:
            display.clearDisplay();
            display.drawBitmap(48, 20, signal, 32, 24, SSD1306_WHITE);
            display.display();
            //redLED.blink(10, 500);
            delay(1000);
            //play signal
            break;
        case 1:
            //redLED.blink(50, 1000);
            break;
        case 2:
            //redLED.light(500);
            break;
        case 3:
            //redLED.blink(100, 10000);
            break;
        default:

            break;
      }//switch
    }//if
    display.display();
  }//while
};*/
void usbHak5() {
  Empty();
};
bool enablePause=false;
void countdown(int mins) {
  int secs=1; //leave 1 so that its displeys 00:00
  delay(200);
  display.clearDisplay();
  while (true) {
    buttons();
    delay(976);
    display.fillRect(33, 22, 91, 14, SSD1306_BLACK);
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(57, 22);
    display.print(F(":"));
    secs --;
    buttons();

    if (secs < 0) {
      mins--;
      secs=59;
      }
    if (mins < 0) {
      mins=0;
      secs=0;
    }
    if (mins<10) {
      display.setCursor(45, 22);
      display.print(mins);
      display.setCursor(33, 22);
      display.print(("0"));
    }
    else {
      display.setCursor(33, 22);
      display.print(mins);
    }

    if (secs<10) {
      display.setCursor(81, 22);
      display.print(secs);
      display.setCursor(69, 22);
      display.print(("0"));
    }
    else {
      display.setCursor(69, 22);
      display.print(secs);
    }

    display.display();

    if (mins==0 && secs==0) {
      delay(100);
      buttons();
      if (EncoderSW) {
        if (lockScreen==true) {
          password();
          }
        break;}   
    }  //if (mins==0 && secs==0)

    if (SideSW && enablePause) {
      debounce(&SideSW);
      while (true) {
        buttons();
        if (SideSW) {debounce(&SideSW); break;}
      }
    }//if SideSW

  }//while
};
unsigned int setTime = newPosition;
bool TimerOptionsValues[4] {false, false, false, false};
void Timer() {
  setZero();
  debounce(&EncoderSW);
  delay(400);
  display.clearDisplay();
  while(true) {
    rotary_encoder();
    setTime = newPosition;
    if (setTime > 99) {setTime=99;}
    display.fillRect(70, 0, 50, 8, SSD1306_BLACK);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(F("Timer Delay: "));
    display.print(setTime);
    display.display();

    if (SideSW) {
      isHome=true;
      setZero();
      debounce(&EncoderSW);
      display.clearDisplay();
      break;
    }
    if (EncoderSW) {
      debounce(&EncoderSW);
      break;
    }

    display.drawBitmap(2, 16, checkbox_unselected, 7, 7, SSD1306_WHITE);
    display.drawBitmap(2, 28, checkbox_unselected, 7, 7, SSD1306_WHITE);
    display.drawBitmap(2, 40, checkbox_unselected, 7, 7, SSD1306_WHITE);
    display.drawBitmap(2, 52, checkbox_unselected, 7, 7, SSD1306_WHITE);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 16);
    display.println(F("Lock Screen"));
    display.setCursor(19, 28);
    display.println(F("Allow Pause"));
    display.setCursor(19, 40);
    display.println(F("Pin Charge"));
    display.setCursor(19, 52);
    display.println(F("Start!!!"));
  } //while 1

  setZero();
  int TimerOption=0;
  int TimerEncoder=0;

  while (isHome==false) {
    rotary_encoder();
    
    if (newPosition > TimerEncoder) {
      TimerOption ++;
      if (TimerOption > 3) {
        TimerOption=3;
        }
      TimerEncoder = newPosition;
      }
    else if (newPosition < TimerEncoder) {
      TimerOption --;
      if (TimerOption < 0) {
      TimerOption=0;
      }
      TimerEncoder = newPosition;}
    
    // Clear old lines
    display.drawFastVLine(0, 16, 46, SSD1306_BLACK);
    display.drawFastVLine(10, 16, 46, SSD1306_BLACK);
    // Draw new arrow at TimerOption
    int y = 16 + TimerOption * 12;
    display.drawFastVLine(0, y, 7, SSD1306_WHITE);
    display.drawFastVLine(10, y, 7, SSD1306_WHITE);

    if (EncoderSW) {
      TimerOptionsValues[TimerOption] = !TimerOptionsValues[TimerOption];
      // Clear old lines
      display.fillRect(2, y, 7, 7, SSD1306_BLACK);
      // Draw new arrow at TimerOption
      if (TimerOptionsValues[TimerOption] == true) {
        display.drawBitmap(2, y, checkbox_selected, 7, 7, SSD1306_WHITE);
      }
      else if (TimerOptionsValues[TimerOption] == false) {
        display.drawBitmap(2, y, checkbox_unselected, 7, 7, SSD1306_WHITE);
      }
      debounce(&EncoderSW);
    }
    display.display();

    if (SideSW) {
      isHome=true;
      setZero();
      debounce(&EncoderSW);
      display.clearDisplay();
      break;
    }

    if (TimerOptionsValues[0]==true) {
      lockScreen=true;
    }
    else { lockScreen=false;
    }
    if (TimerOptionsValues[1]==true) {
    }
    if (TimerOptionsValues[2]==true) {
      enablePause=true;
    }
    else {enablePause=true;
    }
    if (TimerOptionsValues[3]==true) {
      countdown(setTime);
      display.clearDisplay();
      break;
    }

  } //while 2

  isHome=true;
  setZero();
  debounce(&EncoderSW);
  delay(400);
};
void Empty() {
  display.fillRect(0, 16, 128, 46, SSD1306_BLACK);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(46, 24);
  display.println(F("Empty!"));
  display.setCursor(42, 36);
  display.println(F("Go Back"));
  
  while (true) {
    battery_scroll();
    time("12:36");
    display.display();
    buttons();
    if (SideSW) {
      setZero();
      display.clearDisplay();
      isHome=true;
      return;
    }
  }//while
};
int keyboardMode=0;  //0=upper, 1=lower, 2=number, 3=symbol
int keyPos=0;
bool backspaceSwap=false;
String keyboardText="";
void keyboard() {
  debounce(&SideSW);
  setZero();
  display.clearDisplay();
  display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
  while (true) {
    rotary_encoder();
    keyPos=newPosition;
    if (keyboardMode==0) {
      display.setTextSize(1);
      display.setTextColor(SSD1306_BLACK);
      switch (keyPos) {
        case 0:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(1, 28, 13, 11, SSD1306_WHITE);
          display.drawBitmap(5, 31, commandLogo, 6, 5, SSD1306_BLACK);
          break;
        case 1:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(15, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(17, 30);
          display.println('Q');
          break;
        case 2:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(25, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(27, 30);
          display.println('W');
          break;
        case 3:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(35, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(37, 30);
          display.println('E');
          break;
        case 4:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(45, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(47, 30);
          display.println('R');
          break;
        case 5:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(55, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(57, 30);
          display.println('T');
          break;
        case 6:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(65, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(67, 30);
          display.println('Y');
          break;
        case 7:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(75, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(77, 30);
          display.println('U');
          break;
        case 8:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(85, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(87, 30);
          display.println('I');
          break;
        case 9:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(95, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(97, 30);
          display.println('O');
          break;
        case 10:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(105, 28, 9, 11, SSD1306_WHITE);
          display.setCursor(107, 30);
          display.println('P');
          break;
        case 11:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          if (backspaceSwap==false) {
            display.fillRect(115, 28, 12, 11, SSD1306_WHITE);
            display.drawBitmap(117, 31, backspaceLogo, 8, 5, SSD1306_BLACK);
          }
          else if (backspaceSwap==true) {
            display.fillRect(115, 28, 12, 11, SSD1306_WHITE);
            display.drawBitmap(117, 35, spaceLogo, 8, 2, SSD1306_BLACK);
          }
          break;
        case 12:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(1, 40, 17, 11, SSD1306_WHITE);
          display.drawBitmap(7, 42, shiftLogo, 5, 7, SSD1306_BLACK);
          break;
        case 13:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(19, 40, 9, 11, SSD1306_WHITE);
          display.setCursor(21, 42);
          display.println('A');
          break;
        case 14:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(29, 40, 9, 11, SSD1306_WHITE);
          display.setCursor(31, 42);
          display.println('S');
          break;
        case 15:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(39, 40, 9, 11, SSD1306_WHITE);
          display.setCursor(41, 42);
          display.println('D');
          break;
        case 16:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(49, 40, 9, 11, SSD1306_WHITE);
          display.setCursor(51, 42);
          display.println('F');
          break;
        case 17:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(59, 40, 9, 11, SSD1306_WHITE);
          display.setCursor(61, 42);
          display.println('G');
          break;
        case 18:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(69, 40, 9, 11, SSD1306_WHITE);
          display.setCursor(71, 42);
          display.println('H');
          break;
        case 19:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(79, 40, 9, 11, SSD1306_WHITE);
          display.setCursor(81, 42);
          display.println('J');
          break;
        case 20:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(89, 40, 9, 11, SSD1306_WHITE);
          display.setCursor(91, 42);
          display.println('K');
          break;
        case 21:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(99, 40, 9, 11, SSD1306_WHITE);
          display.setCursor(101, 42);
          display.println('L');
          break;
        case 22:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(109, 40, 18, 11, SSD1306_WHITE);
          display.drawBitmap(112, 43, enterLogo, 12, 5, SSD1306_BLACK);
          break;
        case 23:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(1, 52, 21, 11, SSD1306_WHITE);
          display.drawBitmap(3, 54, numbersLogo, 18, 7, SSD1306_BLACK);
          break;
        case 24:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(23, 52, 9, 11, SSD1306_WHITE);
          display.setCursor(25, 54);
          display.println('Z');
          break;
        case 25:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(33, 52, 9, 11, SSD1306_WHITE);
          display.setCursor(35, 54);
          display.println('X');
          break;
        case 26:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(43, 52, 9, 11, SSD1306_WHITE);
          display.setCursor(45, 54);
          display.println('C');
          break;
        case 27:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(53, 52, 9, 11, SSD1306_WHITE);
          display.setCursor(55, 54);
          display.println('V');
          break;
        case 28:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(63, 52, 9, 11, SSD1306_WHITE);
          display.setCursor(65, 54);
          display.println('B');
          break;
        case 29:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(73, 52, 9, 11, SSD1306_WHITE);
          display.setCursor(75, 54);
          display.println('N');
          break;
        case 30:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(83, 52, 9, 11, SSD1306_WHITE);
          display.setCursor(85, 54);
          display.println('M');
          break;
        case 31:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(93, 52, 8, 11, SSD1306_WHITE);
          display.setCursor(94, 54);
          display.println(',');
          break;
        case 32:
          display.fillRect(0, 27, 128, 37, SSD1306_BLACK);
          display.drawBitmap(0, 27, keyboardUppercase, 128, 37, SSD1306_WHITE);
          display.fillRect(102, 52, 8, 11, SSD1306_WHITE);
          display.setCursor(103, 53);
          display.println('.');
          break;
      }
      if ((keyPos!=11) && (backspaceSwap==true)) {
        display.fillRect(115, 28, 12, 11, SSD1306_BLACK);
        display.drawBitmap(117, 35, spaceLogo, 8, 2, SSD1306_WHITE);
      }
      display.fillRect(0, 0, 128, 15, SSD1306_BLACK);
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(keyboardText);
      display.display();
    }//if
    if (EncoderSW) {
      debounce(&EncoderSW);
      switch (keyPos) {
        case 0:
          backspaceSwap = !backspaceSwap;
          break;
        case 1:
          keyboardText+='Q';
          break;
        case 2:
          keyboardText+='W';
          break;
        case 3:
          keyboardText+='E';
          break;
        case 4:
          keyboardText+='R';
          break;
        case 5:
          keyboardText+='T';
          break;
        case 6:
          keyboardText+='Y';
          break;
        case 7:
          keyboardText+='U';
          break;
        case 8:
          keyboardText+='I';
          break;
        case 9:
          keyboardText+='O';
          break;
        case 10:
          keyboardText+='P';
          break;
        case 11:
          if ((backspaceSwap==false) && (keyboardText.length() > 0)) {
            display.clearDisplay();
            keyboardText.remove(keyboardText.length() - 1);}
          else if (backspaceSwap==true) {
            keyboardText+=' ';}
          break;
        case 12:
          goto skip;
          break;
        case 13:
          keyboardText+='A';
          break;
        case 14:
          keyboardText+='S';
          break;
        case 15:
          keyboardText+='D';
          break;
        case 16:
          keyboardText+='F';
          break;
        case 17:
          keyboardText+='G';
          break;
        case 18:
          keyboardText+='H';
          break;
        case 19:
          keyboardText+='J';
          break;
        case 20:
          keyboardText+='K';
          break;
        case 21:
          keyboardText+='L';
          break;
        case 22:
          keyboardText+='\n';
          break;
        case 23:
          goto skip;
          break;
        case 24:
          keyboardText+='Z';
          break;
        case 25:
          keyboardText+='X';
          break;
        case 26:
          keyboardText+='C';
          break;
        case 27:
          keyboardText+='V';
          break;
        case 28:
          keyboardText+='B';
          break;
        case 29:
          keyboardText+='N';
          break;
        case 30:
          keyboardText+='M';
          break;
        case 31:
          keyboardText+=',';
          break;
        case 32:
          keyboardText+='.';
          break;
        case 33:
          goto skip;
          break;
        default:
          skip:
          display.clearDisplay();
          return;
      }
    }//if EncoderSW

    if (SideSW) {
      debounce(&SideSW);
      if (backspaceSwap==false) {
        keyboardText+=' ';}
      else if ((backspaceSwap==true) && (keyboardText.length() > 0)) {
        display.clearDisplay();
        keyboardText.remove(keyboardText.length() - 1);}
    }//if SideSW


  }//while
};
void SerialCom() {
  keyboard:
  debounce(&EncoderSW);
  keyboard();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(keyboardText);
  display.display();

  while (true) {
    buttons();
    if (SideSW) {
      isHome=true;
      return;
    }
    if (EncoderSW) {
      goto keyboard;
    }
  }
};
void testdrawchar(void) {
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for(int16_t i=0; i<256; i++) {
    if(i == '\n') display.write(' ');
    else          display.write(i);
  }

  display.display();
  
  while (true) {
    buttons();
    if (SideSW) {
      isHome=true;
      return;
    }
  }
};
void External() {
  display.clearDisplay();
  display.setTextSize(4);
  display.setCursor(0, 16);
  display.cp437(true);
  //display.print(F(""));//
  display.write(210);
  display.write(211);
  display.write(212);
  display.write(213);
  //display.write(7);
  //display.write(8);
  display.display();

  while (true) {
    buttons();
    if (SideSW) {
      isHome=true;
      return;
    }
  }//*/
};
void Lock_Screen() { 
  setZero();
  lockScreen=true;
  delay(500);
  
  /*int xpos(0), ypos(0);
  display.clearDisplay();
  while (lockScreen) {
    if (xpos > 127) {xpos=0; ypos++;}
    if (ypos > 63) {ypos=0;}
    display.clearDisplay();
    display.drawPixel(xpos, ypos, SSD1306_WHITE);
    xpos++;
    display.drawPixel(xpos, ypos, SSD1306_WHITE);
    xpos++;
    display.drawPixel(xpos, ypos, SSD1306_WHITE);
    xpos++;
    display.drawPixel(xpos, ypos, SSD1306_WHITE);
    xpos++;
    display.display();
    //delay();

    buttons();
    
    if (EncoderSW) {
      delay(0);
      setZero();
      password();
    }
  }//while loop     */
  /*int x=0, y=0;
  int side = 0;
  while (lockScreen) {
    display.clearDisplay();
    // Draw dot
    display.drawPixel(x, y, SSD1306_WHITE);
    display.display();

    // Move dot along the edge
    switch (side) {
      case 0:  // top → right
        x++;
        if (x >= 127) { side = 1; }
        break;
      case 1:  // right → bottom
        y++;
        if (y >= 63) { side = 2; }
        break;
      case 2:  // bottom → left
        x--;
        if (x <= 0) { side = 3; }
        break;
      case 3:  // left → top
        y--;
        if (y <= 0) { side = 0; }
        break;
    }
    //delay(5);
  }//while  */
  
  while (lockScreen) {
    for (int i=16; i<46; i++) {
      display.clearDisplay();
      display.drawFastHLine(14, i, 100, SSD1306_WHITE);
      display.display();
    }
    buttons();
      if (EncoderSW) {
        debounce(&SideSW);
        setZero();
        password();
        break;
      }
    for (int i=46; i>15; i--) {
      display.clearDisplay();
      display.drawFastHLine(14, i, 100, SSD1306_WHITE);
      display.display();
    }
    buttons();
      if (EncoderSW) {
        debounce(&EncoderSW);
        setZero();
        password();
        break;
      }
  }//while
};


void loop() {
  //Lock_Screen(); in setup
  buttons();
  rotary_encoder();
  Task();
  time("12:36");
  battery_scroll();
} //void loop end