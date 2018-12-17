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



int checkWinner(Character cat, Character mouse, int& roundNumber) //<----add stuff to this function
{
  if(
    (cat.getHead().getDotX() == mouse.getHead().getDotX() && cat.getHead().getDotY() == mouse.getHead().getDotY()) 
     || (cat.getTail().getDotX() == mouse.getTail().getDotX() && cat.getTail().getDotY() == mouse.getTail().getDotY()) 
     || (cat.getHead().getDotX() == mouse.getTail().getDotX() && cat.getTail().getDotY() == mouse.getHead().getDotY())
     || (cat.getTail().getDotX() == mouse.getHead().getDotX() && cat.getHead().getDotY() == mouse.getTail().getDotY())
     )
  {
    if(roundNumber >= 3)
      {
        delay(100);
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Winner is:");
        lcd.setCursor(0, 1);
        lcd.print("plm");
        roundNumber = 0;
        turnOffMatrix();
        
      }
    else
      roundNumber++;
 // return roundNumber;
}
}

Dot generatePowerUp() //this works, but get back to it
{
  Dot powerUp;
  powerUp.setDotX(rand()%8);
  powerUp.setDotY(rand()%8);
  return powerUp;
}


void printRoundNumberOnLCD(int roundNumber)
{
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Round ");
    lcd.setCursor(10, 0);
    lcd.print(roundNumber+1);
  
}


int controlDelay(unsigned long& timeGiven, unsigned long delayWanted)
{
  unsigned long timeNow = millis();
  if(timeGiven - timeNow >= delayWanted)
    {
      timeGiven = timeNow;
      return 1;
    }
  else
    {
     // timeGiven = timeNow;
      controlDelay(timeNow, delayWanted);
     }  
}
