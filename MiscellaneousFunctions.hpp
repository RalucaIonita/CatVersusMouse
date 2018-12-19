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



int checkWinner(Character cat, Character mouse) //<----add stuff to this function
{
  if(
    (cat.getHead().getDotX() == mouse.getHead().getDotX() && cat.getHead().getDotY() == mouse.getHead().getDotY()) 
     || (cat.getTail().getDotX() == mouse.getTail().getDotX() && cat.getTail().getDotY() == mouse.getTail().getDotY()) 
     || (cat.getHead().getDotX() == mouse.getTail().getDotX() && cat.getTail().getDotY() == mouse.getHead().getDotY())
     || (cat.getTail().getDotX() == mouse.getHead().getDotX() && cat.getHead().getDotY() == mouse.getTail().getDotY())
     )
  {
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("The cat got you!");
        lcd.setCursor(0, 1);
        unsigned int timeNow = millis();
        lcd.print("Again? <Yes >No");
        turnOffMatrix();
        int indexOx = analogRead(JOY_X);
     //   if(millis() >= BASIC_DELAY)
        {
          if(indexOx <=450)
            return 1;
           else
         if(indexOx >= 550)
          return 0;
        }
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


int controlTime(unsigned long& timeSinceGameStart, unsigned int levelTime)
{
  if(timeSinceGameStart >= levelTime)
    {
      turnOffMatrix();
      return 0;
    }
  else
    return 1;
}
