#include "game.h"

uint8_t playerX = 10;
uint8_t playerY = 28;

int8_t bulletX[3] = {-1, -1, -1};
int8_t bulletY[3] = {-1, -1, -1};

int8_t bombX = -1;
int8_t bombY = -1;

void fire()
{
    for(uint8_t i = 0; i < 3; ++i)
    {
        if(bulletX[i] < 0)
        {
            sound.tone(NOTE_C7, 50);
            bulletX[i] = playerX + 16;
            bulletY[i] = playerY + 4;
            break;
        }
    }
}

void bomb()
{
    if(bombY < 0)
    {
        sound.tone(NOTE_A1, 50);
        bombX = playerX + 8;
        bombY = playerY + 8;
    }
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

void move()
{
    // bullets
    for(uint8_t i = 0; i < 3; ++i)
    {
        if(bulletX[i] > 0)
        {
            bulletX[i] += 2;
        }
    }

    // bomb
    if(bombY > 0 && bombY < 64)
    {
        ++bombX;
        ++bombY;
    }
    else if(bombY >= 64)
    {
        bombX = -1;
        bombY = -1;
    }
}

void draw()
{
    // Player
    arduboy.drawRect(playerX, playerY, 16, 8);

    // bullets
    for(uint8_t i = 0; i < 3; ++i)
    {
        if(bulletX[i] > 0)
        {
            arduboy.drawLine(bulletX[i], bulletY[i], bulletX[i] + 4, bulletY[i]);
        }
    }

    // bomb
    if(bombY > 0)
    {
        arduboy.drawCircle(bombX, bombY, 1);
    }
}

void gamePlay()
{
    input();
    move();
    draw();
}