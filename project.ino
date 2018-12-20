#include "MiscellaneousFunctions.hpp"
#include "Setup.hpp"

int ix, iy;
int k = -2;
Character mousePlayer("mouse"), catPlayer("cat");
Character initialMouse("mouse"), initialCat("cat");

int levelNumber = 1;
int controlVariable = 0;


unsigned long timeNowMouse = 0, timeBeforeMouse = 0;
unsigned long timeNowCat = 0, timeBeforeCat = 0;
unsigned long timeSinceStart = 0, lastTryTime = 0;
unsigned long timeUntilNow = 0;


void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(V0_PIN, OUTPUT);
  analogWrite(V0_PIN, 90);
  
  Serial.begin(9600);
  ledMatrix.shutdown(0, false);
  ledMatrix.setIntensity(0, 0);
  ledMatrix.clearDisplay(0);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if(controlVariable == 0)
  {
    mousePlayer = initialMouse;
    catPlayer = initialCat;
    lcd.setCursor(0, 0);
    lcd.print(" Press joystick ");
    lcd.setCursor(0, 1);
    lcd.print("button to start.");

    timeSinceStart = 0;
    k = -2;
  
    controlVariable = 1;
}

  
  if(digitalRead(BUTTON_PIN) == 0 && controlVariable == 1)
  {
    controlVariable = 2;
    lcd.clear();
    timeUntilNow = millis();
  }
  
  Serial.print("timeSinceStart");
  Serial.println(timeSinceStart);


  if(controlTime(timeSinceStart, LEVEL_TIME) == 1 && controlVariable == 2)
  {
    timeSinceStart = millis() - timeUntilNow;

    
  Serial.print("timeSinceStart in if");
  Serial.println(timeSinceStart);


    
    lcd.setCursor(0, 0);
    lcd.print("      Level      ");
    lcd.setCursor(0, 1);
    lcd.print("        ");
    lcd.print(levelNumber);
    lcd.print("        ");

    
    if(controlDelay(timeNowMouse, DELAY_MOUSE) != timeBeforeMouse)
      {  
         mousePlayer.moveMouse(analogRead(JOY_X), analogRead(JOY_Y));
         timeBeforeMouse = timeNowMouse;
     }

     if(controlDelay(timeNowCat, catDelaysVector[levelNumber]) != timeBeforeCat)
      {  
         catPlayer.moveCat(mousePlayer);
         timeBeforeCat = timeNowCat;
      }

      
    k = checkWinner(catPlayer, mousePlayer);
    if(k == 0)
      controlVariable = 0;
    }
  else
  {
    if(k == -1)
     {
      levelNumber++;
      
      controlVariable = 0;
     }
  }

  if(levelNumber == 8)
    levelNumber = 1;
}
