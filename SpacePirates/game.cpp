#include "game.h"

int playerX = 10;
int playerY = 28;

void fire()
{

}

void bomb()
{
    gameState = STATE_GAME_OVER;
}

void input()
{
    if(arduboy.pressed(UP_BUTTON) && playerY > 0)
        --playerY;
    else if(arduboy.pressed(DOWN_BUTTON) && playerY < 56)
        ++playerY;

    if(arduboy.pressed(LEFT_BUTTON) && playerX > 0)
        --playerX;
    else if(arduboy.pressed(RIGHT_BUTTON) && playerX < 48)
        ++playerX;

    if(arduboy.justPressed(A_BUTTON))
        fire();

    if(arduboy.justPressed(B_BUTTON))
        bomb();
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