#include "MiscellaneousFunctions.hpp"
#include "Setup.hpp"

Character dummie("mouse"), dummie2("cat");
int ix, iy;

int levelNumber = 1;

unsigned long timeNowMouse = 0, timeBeforeMouse = 0;
unsigned long timeNowCat = 0, timeBeforeCat = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Press joystick");
  lcd.setCursor(0, 1);
  lcd.print("button to start.");
  pinMode(V0_PIN, OUTPUT);
  analogWrite(V0_PIN, 90);
  
  Serial.begin(9600);
  ledMatrix.shutdown(0, false);
  ledMatrix.setIntensity(0, 0);
  ledMatrix.clearDisplay(0);
  pinMode(BUTTON, INPUT_PULLUP);
  turnOffMatrix();
}

void loop() {
  if(controlDelay(timeNowMouse, DELAY_MOUSE) != timeBeforeMouse)
      {
         ix = analogRead(JOY_X);
         iy = analogRead(JOY_Y);      
         dummie.moveMouse(ix, iy);
         timeBeforeMouse = timeNowMouse;
      }
}
