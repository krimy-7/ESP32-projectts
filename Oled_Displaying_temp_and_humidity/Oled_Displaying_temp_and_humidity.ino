#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

DHT dht(5, DHT11);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int xPos = SCREEN_WIDTH; // Start position is at the right edge

void setup() {
  dht.begin();
  delay(2000);
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); 
  }
  
  display.clearDisplay();
  display.setTextSize(2);      
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);  
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  // 1. Combine everything into one string
  String fullMessage = "Temp: " + String(temp, 1) + "C  Humidity: " + String(humidity, 0) + "%";
  
  display.clearDisplay();
  
  // 2. Set the cursor and print the whole string at once
  display.setCursor(xPos, 20); 
  display.print(fullMessage);
  display.display();
  
  // 3. Move the position to the left
  xPos = xPos - 3; // Increased speed slightly for better flow
  
  // 4. Reset based on the length of the FULL message
  // At TextSize 2, each character is about 12 pixels wide
  int messageWidth = fullMessage.length() * 12;
  
  if (xPos < -messageWidth) {
    xPos = SCREEN_WIDTH;
  }
  
  delay(10); // Short delay to keep the scroll smooth
}