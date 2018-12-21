This is my first Arduino project, the game "Cat Versus Mouse", on a 8x8 LED matrix.

For this project, the next components were used:
- an Arduino Uno board
- a 8x8 LED 1088AS matrix
- two breadboards
- an LCD screen
- a MAX7219 driver for the matrix
- jumper cables
- a joystick
- two resistences
- an USB Arduino cable

The game starts with the message "Press joystick button to start.".
If the button is pressed, the game starts with two "characters" (four LEDs in HIGH state, two for each character). The two LEDs from the left are the "Mouse" character, the other two are the "Cat" character. You are playing as the Mouse. The purpose of the game is to survive 45 seconds running from the Cat.
If you do, you get to the next level. With each level, the Cat starts moving faster.
If you don't, you get to chose whether you want to try again or not.
If you chose "Yes", you get back to the level you lost, in the position that the cat got you in and you have less than a second to run from that position.
If you chose "No", you get back to the start state (level 1), and the LCD will show you the message "Press joystick button to start.".
