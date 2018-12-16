#include "MiscellaneousFunctions.hpp"

Character dummie("mouse"), dummie2("cat");
int ix, iy;

Dot k;

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
  ledMatrix.setIntensity(0, 0); // sets brightness
  ledMatrix.clearDisplay(0);// clear screen
  pinMode(BUTTON, INPUT_PULLUP);
  turnOffMatrix();
  dummie.setCharacter(HIGH);
  dummie2.setCharacter(HIGH);
  
}

void loop() {
    ix = analogRead(JOY_X);
    iy = analogRead(JOY_Y);
    dummie.moveCharacter(ix, iy);
    dummie2.moveCat(dummie);
    delay(100);

}
