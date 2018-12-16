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



int checkWinner(Character cat, Character mouse, int roundNumber) //<----add stuff to this function
{
  if( cat == mouse )
  {
    if(roundNumber == 3)
      {
        //print on the lcd the winner
        roundNumber=0;
      }
    else
      roundNumber++;
  }
  return roundNumber;
}


Dot generatePowerUp() //this works, but get back to it
{
  Dot powerUp;
  powerUp.setDotX(rand()%8);
  powerUp.setDotY(rand()%8);
  return powerUp;
}
