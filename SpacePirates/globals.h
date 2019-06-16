#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <Arduboy2.h>

#define STATE_GAME_INTRO    0
#define STATE_GAME_PLAY     1
#define STATE_GAME_OVER     2

extern Arduboy2 arduboy;
extern byte gameState;

#endif