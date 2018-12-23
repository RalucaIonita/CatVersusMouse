	This is my first Arduino project, the game "Cat Versus Mouse", on a 8x8 LED matrix.



* Gameplay:

	The game starts with the message "Press joystick button to start.".
	If the button is pressed, the game starts with two "characters" (four LEDs in HIGH state, two for each character). The two LEDs from the left are the "Mouse" character, the other two are the "Cat" character. You are playing as the Mouse. The purpose of the game is to survive 25 seconds running from the Cat.
	If you do, you get to the next level. With each level, the Cat starts moving faster.
       If you don't, you get to choose whether you want to try again or not.
	If you chose "Yes", you get back to the level you lost, in the position that the cat got you in and you have less than a second to run from that position.
	If you chose "No", you get back to the start state (Level 1), and the LCD will show you the message "Press joystick button to start.".


* Hardware components:

	For this project, the next components were used:
- an Arduino Uno board
- a 8x8 LED 1088AS matrix
- two breadboards
- an LCD screen
- a MAX7219 driver for the matrix
- jumper cables
- a joystick
- two resistors
- an USB Arduino cable


![The components anssembled](https://github.com/RalucaIonita/CatVersusMouse/issues/1#issue-393780955)



* Software components

The software of the game has the next components:
- the “project.ino” file
- the “Setup.hpp” header
- the “CharacterAndDot.hpp” header
- the “MiscellaneousFunctions.hpp” header
	
	In “Setup.hpp” header:
- the next variables were declared:
	- ledMatrix (as const LedControl)
	- lcd (as const LiquidCrystal)
	- catDelaysVector (as const int, an unidimensional array with 8 elements)
- the next variables were defined:
       - NUMBER_OF_LEDS (as 8)
       - JOY_X (as A0)
       - JOY_Y (as A1)
       - BUTTON_PIN (as 13)
       - V0_PIN (as 9)
       - DELAY_MOUSE (as 100)
       - LEVEL_TIME (as 25000)
       - BASIC_TIME (as 10000)
       - LAST_LEVEL (as 8)
       - FIRST_LEVEL (as 1)
       - MEMORY_ADDRESS_FOR_HIGHEST_SCORE (as 0)
- the next function was declared:
	- cleanEEPROMMemory()
	
	In “CharacterAndDotClass.hpp” header:
- two classes were declared:
       - Dot, with:
       	- private data:
       		- x (integer, coordinate on ox axis)
       		- y (integer, coordinate on oy axis)
       	- public methods:
       		- constructor
       		- destructor
       		- getters (for x coordinate and for y coordinate)
       		- setters (for x coordinate, for y coordinate and for both coordinates)
       		- overloading of “=” operator
       		- setDot (method for setting HIGH or LOW the LED on the matrix with the x and y coordinates)
       - Character, with:
       - private data:
       		- head (Dot)
       		- tail (Dot)
       	- public methods:
       		- constructor
       		- parametrized constructor
       		- destructor
       		- getters (for head and for tail)
       		- setters (for head and for tail)
       		- overloading of “=” operator
       		- setCharacter (method for setting HIGH or LOW the LEDs on the matrix with the coordinates of the head and the tail)
       		- moveMouse (method for moving the mouse character
       		- moveCat (method for moving the cat character)
	
	In “MiscellaneousFunctions.hpp” header:
- the next functions were declared:
	- startGame
	- turnOffMatrix
	- controlTime
	- checkWinner
	- controlDelay
	- printAskingForJoystickInputOnLCD
	- printLevelUpOnLCD
	- saveScore
	- printScoreOnLCD

	In “project.ino” file, the Arduino board gets the input and starts the game. Each moment, it checks the winner and develops the game using the functions previously mentioned.

	
* Built with:
	- Arduino IDE
	- Notepad++

* Game:
https://drive.google.com/open?id=1nuWeUky8t0izUVQVvhpHhyA7vpLWy9oj




