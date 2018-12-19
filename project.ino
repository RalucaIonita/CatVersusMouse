#include "MiscellaneousFunctions.hpp"
#include "Setup.hpp"

int ix, iy;
Character mousePlayer("mouse"), catPlayer("cat");
Character initialMouse("mouse"), initialCat("cat");

int levelNumber = 1;
int controlVariable = 0;

//unsigned long catDelay = DELAY_CAT_LEVEL_1;

unsigned long timeNowMouse = 0, timeBeforeMouse = 0;
unsigned long timeNowCat = 0, timeBeforeCat = 0;
unsigned long timeSinceStart = 0;


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
    
    lcd.setCursor(1, 0);
    lcd.print("Press joystick");
    lcd.setCursor(0, 1);
    lcd.print("button to start.");
  
  controlVariable = 1;
}

  
  if(digitalRead(BUTTON_PIN) == 0 && controlVariable == 1)
  {
    controlVariable = 2;
    lcd.clear();
  }

  if(controlTime(timeSinceStart, LEVEL_TIME) == 1 && controlVariable == 2)
  {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Level");
    lcd.setCursor(7, 1);
    lcd.print(levelNumber);

    
  
    timeSinceStart = millis() - (levelNumber-1)*LEVEL_TIME;
    if(controlDelay(timeNowMouse, DELAY_MOUSE) != timeBeforeMouse)
      {  
         mousePlayer.moveMouse(analogRead(JOY_X), analogRead(JOY_Y));
         timeBeforeMouse = timeNowMouse;
     }

     if(controlDelay(timeNowCat, DELAY_CAT_LEVEL_1) != timeBeforeCat)
      {  
         catPlayer.moveCat(mousePlayer);
         timeBeforeCat = timeNowCat;
      }
    Serial.println(timeSinceStart);

    if(checkWinner(catPlayer, mousePlayer) == 0)
    {
      controlVariable = 0;
    }
  }
  else
      controlVariable = 0;
}
