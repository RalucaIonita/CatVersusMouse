#pragma once

#include "LedControl.h"
#include "LiquidCrystal.h"

const LedControl ledMatrix = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER
const LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define NUMBER_OF_LEDS 8


#define JOY_X A0
#define JOY_Y A1
#define BUTTON_PIN 13
#define V0_PIN 9


#define DELAY_MOUSE 100

#define LEVEL_TIME 45000
#define BASIC_DELAY 150000


const int catDelaysVector[8] = {850, 750, 650, 550, 450, 350, 250, 150};
