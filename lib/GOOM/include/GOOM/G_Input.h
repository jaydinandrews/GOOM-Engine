#ifndef INPUT_H
#define INPUT_H

#include "G_Settings.h"
#include "G_Game.h"
#include "M_Menu.h"

uint16_t G_KeyRegisters(game_t *game, uint8_t key);
uint8_t G_KeyJustPressed(game_t *game, uint8_t key);
uint8_t G_KeyRepeated(game_t *game, uint8_t key);


#endif /* INPUT_H */