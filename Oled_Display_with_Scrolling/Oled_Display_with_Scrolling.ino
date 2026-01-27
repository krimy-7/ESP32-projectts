#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Store your message in a variable
String message = "Hi Krimy, Happy Saraswati Pooja!";
int xPos = SCREEN_WIDTH; // Start position is at the right edge
int ledPin =2;
void setup() {
  pinMode(ledPin, OUTPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); // If display fails, stop here
  }
  
  display.clearDisplay();
  display.setTextSize(2);      // Good size for visibility
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);  // CRITICAL: Stops the text from breaking into two lines
}

void loop() {
  
  if (touchRead(T0) < 200)
  
  {
    digitalWrite(ledPin, HIGH);
     display.clearDisplay();
  
  // Set the cursor at the moving X position
  display.setCursor(xPos, 20); 
  display.print(message);
  display.display();
  
  // Move the position to the left
  xPos = xPos - 2; 
  
  // Reset position when the message has fully scrolled off the left side
  // At TextSize 2, each character is roughly 12 pixels wide
  if (xPos < (int)(message.length() * -12)) {
    xPos = SCREEN_WIDTH;
  }
  digitalWrite(ledPin, LOW);
  delay(10); // Adjust this to make it scroll faster or slower
}
}