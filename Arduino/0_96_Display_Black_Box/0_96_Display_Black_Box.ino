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
  
  Lock_Screen();
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
	0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8
};

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
/*void updateDisplayNumber(long value) {
  display.fillRect(0, 0, 30, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(value);
  display.display();
  }*/
void time(const char* time) {
  display.fillRect(0, 0, 58, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(2, 0);
  display.println(time);
  display.display();};
long newPosition = 0;
long lastPosition = -999;
long encoderOffset = 0;
String Options[] = {"Remote", "IR-Reader", "Radio", "Game", "Empty", "Lock Screen", "Counter", "Settings"};
String currentSelected = Options[0];   //0 to start at settings
bool isHome = true;
long taskNum;
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
      delay(400);
    }
    if (SideSW) {
      Lock_Screen();
      break;
    }
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
    if (firstNum==pasNum1 && secondNum==pasNum2 && thirdNum==pasNum3){
    lockScreen=false;
    setZero();
    isHome=true;
    updateMenu(newPosition % NUMBER_of_OPTIONS);
    //updateDisplayNumber(0);
    break;
    }
  }   //lockScreen loop end
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
    Game();}
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
void Settings() {
  Empty();
};
void Remote() {
  
};
void IRreader() {
  Empty();
};
void Game() {
  Empty();
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
void Lock_Screen() { 
  setZero();
  lockScreen=true;
  display.clearDisplay();
  delay(500);
  while (lockScreen) {
    display.clearDisplay();
    buttons();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(33, 22);
    display.println("12:35");
    display.display();
    
    if (EncoderSW) {
      delay(500);
      password();
    }
  }//while loop
};
void Counter() {
  int count=0;
  isHome=false;
  display.clearDisplay();
  display.display();
  delay(400);
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
      delay(800);
    }
  }
  display.clearDisplay();
  display.display();
  updateMenu(6);
  delay(600);
};

void loop() {
  buttons();
  rotary_encoder();
  Task();
  battery_scroll();
  time("12:36");
} //void loop end