#include "game.h"

int playerX = 10;
int playerY = 28;

void input()
{
    if(arduboy.pressed(UP_BUTTON))
    {
        if(playerY > 0)
            --playerY;
    }
    else if(arduboy.pressed(DOWN_BUTTON))
    {
        if(playerY < 56)
            ++playerY;
    }
    if(arduboy.justPressed(A_BUTTON))
        gameState = STATE_GAME_OVER;
}

void draw()
{
    arduboy.drawRect(playerX, playerY, 16, 8);
}

void gamePlay()
{
    input();
    draw();
}