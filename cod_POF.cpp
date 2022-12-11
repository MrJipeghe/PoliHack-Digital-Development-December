#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  delay(2000);
  display.clearDisplay();
  pinMode(7, OUTPUT);

  // Display static text
}

void loop() {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  double x = (double)(analogRead(A0) - 500) * 6 / 500 * 12 * (-1);
  //Serial.print(x,DEC);
  display.print(x);
  display.println(" W");
  display.print(analogRead(A0));
  display.display();
  display.clearDisplay();
  display.setCursor(0, 10);

  digitalWrite(7, HIGH);
  delay(1000);
  x = (double)(analogRead(A0) - 500) * 6 / 500 * 12 * (-1);
  //Serial.print(x,DEC);
  display.print(x);
  display.println(" W");
  display.print(analogRead(A0));
  display.display();
  display.clearDisplay();
  delay(5000);
  display.setCursor(0, 10);
  delay(1000);
  digitalWrite(7, LOW);
  delay(1000);
  x = (double)(analogRead(A0) - 500) * 6 / 500 * 12 * (-1);
  //Serial.print(x,DEC);
  display.print(x);
  display.println(" W");
  display.print(analogRead(A0));
  display.display();
  display.clearDisplay();
  delay(5000);
  x = (double)(analogRead(A0) - 500) * 6 / 500 * 12 * (-1);
  //Serial.print(x,DEC);
  display.print(x);
  display.println(" W");
  display.print(analogRead(A0));
  display.display();
  display.clearDisplay();
  display.clearDisplay();
}