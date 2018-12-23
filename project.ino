#include "MiscellaneousFunctions.hpp"
#include "Setup.hpp"

int ix, iy;
int checkLevelWinner = -2;
Character mousePlayer("mouse"), catPlayer("cat");
Character initialMouse("mouse"), initialCat("cat");

int levelNumber = FIRST_LEVEL;
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
   /* mousePlayer = initialMouse;
    catPlayer = initialCat;*/
    
    printAskingForJoystickInputOnLCD();
    timeSinceStart = 0;
    checkLevelWinner = -2;
  
    controlVariable = 1;
}

  
  if(digitalRead(BUTTON_PIN) == 0 && controlVariable == 1)
  {
    
    mousePlayer = initialMouse;
    catPlayer = initialCat;
    timeSinceStart = 0;
    lcd.clear();
    timeUntilNow = millis();
    
    controlVariable = 2;
  }


  if(controlTime(timeSinceStart, LEVEL_TIME) == 1 && controlVariable == 2)
  {
    timeSinceStart = millis() - timeUntilNow;
    Serial.println(timeSinceStart);

    printLevelOnLCD();
    
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

      
    checkLevelWinner = checkWinner(catPlayer, mousePlayer);
    
    if (checkLevelWinner == 0)
    {
      
      printScoreOnLCD(levelNumber);
      controlVariable = 0;
      levelNumber = FIRST_LEVEL;
     }

   }
  else
  {
    if(checkLevelWinner == -1 && controlVariable == 2)
     {
      levelNumber++;
      printLevelUpOnLCD();      
      controlVariable = 1;
      checkLevelWinner = -2;
     }
  }

  if(levelNumber == LAST_LEVEL)
    levelNumber = FIRST_LEVEL;
}
