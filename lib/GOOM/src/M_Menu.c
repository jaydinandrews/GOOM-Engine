#include "M_Menu.h"
#include <stdint.h>

void M_GameStepMenu(game_t *game) {
  uint8_t menu_items = 0;
  while(M_GetMenuItem(menu_items) != MENU_ITEM_NONE) {
    menu_items++;
  }

  uint8_t item = M_GetMenuItem(game->selected_menu_item);
}

uint8_t M_GetMenuItem(uint8_t index) {
  uint8_t current_item = 0;
  while (1) { // find first valid item
    // skip non valid items (load if no load available)
    current_item++;
    continue;

    if (index == 0) {
      return (current_item <= MENU_ITEM_EXIT) ? current_item : MENU_ITEM_NONE;
    }
    current_item++;
    index--;
  }
  return MENU_ITEM_NONE;
}