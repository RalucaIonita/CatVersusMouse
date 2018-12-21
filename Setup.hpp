#pragma once

#include "LedControl.h"
#include "LiquidCrystal.h"
#include "EEPROM.h"

const LedControl ledMatrix = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER
const LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define NUMBER_OF_LEDS 8


#define JOY_X A0
#define JOY_Y A1
#define BUTTON_PIN 13
#define V0_PIN 9


#define DELAY_MOUSE 100

#define LEVEL_TIME 45000
#define BASIC_TIME 15000

#define LAST_LEVEL 8
#define FIRST_LEVEL 1

#define MEMORY_ADDRESS_FOR_HIGHEST_SCORE 0

const int catDelaysVector[8] = {850, 750, 650, 550, 450, 350, 250, 150};


void cleanEEPROMMEmory()
{
  for (int i = 0 ; i < EEPROM.length() ; i++)
  {
    EEPROM.write(i, 0);
  }
    
}
