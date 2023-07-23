#ifndef INPUT_H
#define INPUT_H

#include "G_Game.h"

#include <stdint.h>

#define KEY_UP 0
#define KEY_RIGHT 1
#define KEY_DOWN 2
#define KEY_LEFT 3
#define KEY_PRIMARY 4
#define KEY_SECONDARY 5
#define KEY_TERTIARY 6
#define KEY_JUMP 7
#define KEY_LEFT_STRAFE 8
#define KEY_RIGHT_STRAFE 9
#define KEY_MAP 10
#define KEY_MENU 11

uint16_t G_KeyRegisters(game_t *game, uint8_t key);
uint8_t G_KeyJustPressed(game_t *game, uint8_t key);
uint8_t G_KeyRepeated(game_t *game, uint8_t key);
uint8_t G_KeyIsDown(game_t *game, uint8_t key);

#endif /* INPUT_H */