#pragma once
#include "CharacterAndDotClass.hpp"
#include "Setup.hpp"


int startGame(int buttonState)
{
  if(buttonState == LOW)
    return 1;
  else return 0;  
}

void turnOffMatrix()
{
  Dot dummie;
  for(int i = 0; i < NUMBER_OF_LEDS; i++)
    for(int j = 0; j < NUMBER_OF_LEDS; j++)
      {
        dummie.setDotCoordinates(i, j);
        dummie.setDot(LOW);
      }
}



int checkWinner(Character cat, Character mouse)
{
  if(
    (cat.getHead().getDotX() == mouse.getHead().getDotX() && cat.getHead().getDotY() == mouse.getHead().getDotY()) 
     || (cat.getTail().getDotX() == mouse.getTail().getDotX() && cat.getTail().getDotY() == mouse.getTail().getDotY()) 
     || (cat.getHead().getDotX() == mouse.getTail().getDotX() && cat.getTail().getDotY() == mouse.getHead().getDotY())
     || (cat.getTail().getDotX() == mouse.getHead().getDotX() && cat.getHead().getDotY() == mouse.getTail().getDotY())
     )
  {
    lcd.setCursor(0, 0);
    lcd.print("The cat got you!");
    lcd.setCursor(0, 1);
    lcd.print("Again? <Yes >No");
    turnOffMatrix();
    int indexOx = analogRead(JOY_X);
    if(indexOx <=450)
     {
       lcd.clear();
       return 1;
     }
     else
      if(indexOx >= 550)
        return 0;
  }
  return -1;
}


unsigned long controlDelay(unsigned long& previousTime, unsigned int delayWanted)
{
  unsigned long currentTime = millis();
  if(currentTime - previousTime > delayWanted)
  {
    previousTime = currentTime;
    return previousTime;
  }
}


int controlTime(unsigned long& timeSinceLevelStart, unsigned int levelTime)
{
  if(timeSinceLevelStart >= levelTime)
    {
      turnOffMatrix();
      return 0;
    }
  else
    return 1;
}


void printAskingForJoystickInputOnLCD()
{
    lcd.setCursor(0, 0);
    lcd.print(" Press joystick ");
    lcd.setCursor(0, 1);
    lcd.print("button to start.");

}


void printLevelUpOnLCD()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Level Up!   ");
    lcd.setCursor(0, 1);
    lcd.print("  Press button. ");
}


void saveScore(int levelNumber)
{
  
  float auxiliarVariable = (float)levelNumber;
  if(levelNumber == 1)
      EEPROM.put(MEMORY_ADDRESS_FOR_HIGHEST_SCORE, auxiliarVariable);
      
  if(EEPROM.read(MEMORY_ADDRESS_FOR_HIGHEST_SCORE) < levelNumber)
  {
    cleanEEPROMMEmory();
    EEPROM.put(MEMORY_ADDRESS_FOR_HIGHEST_SCORE, auxiliarVariable);
  }
}


void printScoreOnLCD(int& levelNumber)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Your score: ");
    lcd.print(levelNumber);
    lcd.setCursor(0, 1);
    lcd.print("Highest score:");
    lcd.print(EEPROM.read(MEMORY_ADDRESS_FOR_HIGHEST_SCORE));
}
