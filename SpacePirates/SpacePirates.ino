// Template for starting Arduboy game projects
//
// Thanks to JO3RI for some of the ideas
//
// License: MIT
#include "intro.h"
#include "game.h"
#include "over.h"

typedef void (*FunctionPointer)();

const FunctionPointer PROGMEM gameStates[] = {
  gameIntro,
  gamePlay,
  gameOver
};

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(60);
}

void loop()
{
  if(!arduboy.nextFrame())
    return;

  arduboy.pollButtons();
  arduboy.clear();
  ((FunctionPointer)pgm_read_word(&gameStates[gameState]))();
  arduboy.display();
}