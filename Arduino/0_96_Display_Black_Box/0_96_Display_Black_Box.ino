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
	0xfe, 0x82, 0x82, 0x82, 0x82, 0x82, 0xfe
};
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
const String Options[] = {"Remote", "IR-Reader", "Radio", "Timer", "Empty", "Lock Screen", "Counter", "Settings"};
String currentSelected = Options[0];   //0 to start at settings
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

  if (SideSW) {
    isHome = true; // Home Button.
    if (isHome) {      //Refreshes home screen when home button is pressed so that you don't need to turn the encoder for it to update the first time
      updateMenu(newPosition % NUMBER_of_OPTIONS);
    } else {
      display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
      display.display();
    }
    delay(400); // Debounce delay
  }
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
    if (EncoderSW || SideSW) {
      selectedDigit = (selectedDigit+1) % 3;
      delay(400);
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
  delay(400);
};
void Task() {
  if (taskNum==0 && EncoderSW==true && isHome) {
    isHome=false;
    Remote();}
  else if (taskNum==1 && EncoderSW==true && isHome) {
    isHome=false;
    IRreader();}
  else if (taskNum==2 && EncoderSW==true && isHome) {
    isHome=false;
    Radio();}
  else if (taskNum==3 && EncoderSW==true && isHome) {
    isHome=false;
    Timer();}
  else if (taskNum==4 && EncoderSW==true && isHome) {
    isHome=false;
    Empty();}
  else if (taskNum==5 && EncoderSW==true && isHome) {
    isHome=false;
    Lock_Screen();}
  else if (taskNum==6 && EncoderSW==true && isHome) {
    isHome=false;
    Counter();}
  else if (taskNum==7 && EncoderSW==true && isHome) {
    isHome=false;
    Settings();}
};
void Radio() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Radio"));
};
int brightnessLevel=0;
void Settings() {
  setZero();
  brightnessLevel=0;
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 16);
  display.println(brightnessLevel);
  display.display();
  
  while (true) {
    rotary_encoder();

    if (brightnessLevel != newPosition && (newPosition>=1 && newPosition<=25) ) {
      brightnessLevel = newPosition * 10;
      display.ssd1306_command(SSD1306_SETCONTRAST);
      display.ssd1306_command(brightnessLevel);
    
      //percentage Bar
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 16);
      display.println(brightnessLevel);
      display.display();
    }
    if (SideSW) {break;}
  }//while
  setZero();
  updateMenu(newPosition % NUMBER_of_OPTIONS);
};
void Remote() {
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
    if (SideSW) {break;}
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
};
void IRreader() {
  Empty();
};
//int global_mins=12;
void countdown(int mins/*=global_mins*/) {
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
        break;
      }  
        
    }  //if (mins==0 && secs==0)
  }//while
};
unsigned int setTime = newPosition;
bool OptionsInfo[4] {false, false, false, false};
void Timer() {
  setZero();
  debounce(&EncoderSW);
  delay(400);
  display.clearDisplay();
  while(true) {
    rotary_encoder();
    setTime = newPosition;
    if (setTime > 99) {setTime=99;}
    display.clearDisplay();
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
  } //while 1

  setZero();
  int TimerOption=0;
  int TimerEncoder=0;

  display.drawBitmap(2, 16, checkbox_unselected, 7, 7, SSD1306_WHITE);
  display.drawBitmap(2, 28, checkbox_unselected, 7, 7, SSD1306_WHITE);
  display.drawBitmap(2, 40, checkbox_unselected, 7, 7, SSD1306_WHITE);
  display.drawBitmap(2, 52, checkbox_unselected, 7, 7, SSD1306_WHITE);

  while (isHome==false) {
    rotary_encoder();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(19, 16);
    display.println(F("Lock Screen"));
    display.setCursor(19, 28);
    display.println(F("Lock Buttons"));
    display.setCursor(19, 40);
    display.println(F("Allow Pause"));
    display.setCursor(19, 52);
    display.println(F("Start!!!"));  //Press SideSW to pause, EncoderSW to play
    
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
      OptionsInfo[TimerOption] = !OptionsInfo[TimerOption];
      // Clear old lines
      display.fillRect(2, y, 7, 7, SSD1306_BLACK);
      // Draw new arrow at TimerOption
      if (OptionsInfo[TimerOption] == true) {
        display.drawBitmap(2, y, checkbox_selected, 7, 7, SSD1306_WHITE);
      }
      else if (OptionsInfo[TimerOption] == false) {
        display.fillRect(2, y, 7, 7, SSD1306_BLACK);
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

    if (OptionsInfo[0]==true) {
      lockScreen=true;
    }
    else { lockScreen=false;
    }
    if (OptionsInfo[1]==true) {
    }
    if (OptionsInfo[2]==true) {
    }
    if (OptionsInfo[3]==true) {
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
  setZero();
  //updateDisplayNumber(0);
  display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(46, 24);
  display.println(F("Empty!"));
  display.setCursor(42, 36);
  display.println(F("Go Back"));
  display.display();
};
void Counter() {
  int count=0;
  isHome=false;
  display.clearDisplay();
  display.display();
  debounce(&EncoderSW);
  while (true) {
    buttons();
    if (EncoderSW) {
      isHome=true;
      count=0;
      break;
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
  display.clearDisplay();
  display.display();
  updateMenu(6);
  delay(600);
};
void Lock_Screen() { 
  setZero();
  lockScreen=true;
  delay(500);
  
  while (lockScreen) {
    buttons();
    //countdown();
    if (EncoderSW) {
      delay(0);
      setZero();
      password();
    }
  }//while loop
};


void loop() {
  //Lock_Screen(); in setup
  buttons();
  rotary_encoder();
  Task();
  time("12:36");
  battery_scroll();
} //void loop end