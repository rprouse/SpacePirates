#include "globals.h"

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

byte gameState = STATE_GAME_INTRO;