#ifndef MENU_H
#define MENU_H

#include "G_Game.h"

#include <stdint.h>

#define MENU_ITEM_CONTINUE 0
#define MENU_ITEM_PLAY 1
#define MENU_ITEM_LOAD 2
#define MENU_ITEM_SOUND 3
#define MENU_ITEM_EXIT 4
#define MENU_ITEM_NONE 255

void M_GameStepMenu(game_t *game);
uint8_t M_GetMenuItem(uint8_t index);


#endif /* MENU_H */