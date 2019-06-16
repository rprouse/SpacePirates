#include "game.h"

void gamePlay()
{
    arduboy.setCursor(0, 10);
    arduboy.println("The game is on");
    arduboy.println("Press A to END");
    if(arduboy.justPressed(A_BUTTON))
        gameState = STATE_GAME_OVER;
}