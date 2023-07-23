#include "M_Menu.h"
#include "G_Game.h"
#include "G_Input.h"
#include "G_Level.h"

void M_GameStepMenu(game_t *game) {
  uint8_t menu_items = 0;
  while(M_GetMenuItem(menu_items) != MENU_ITEM_NONE) {
    menu_items++;
  }

  uint8_t item = M_GetMenuItem(game->current_menu_item);

  if(G_KeyRegisters(game, KEY_DOWN) && (game->current_menu_item < menu_items -1)) {
    game->current_menu_item++;
    //TODO: play sound
  } else if(G_KeyRegisters(game, KEY_UP) && (game->current_menu_item > 0)) {
    game->current_menu_item--;
    //TODO: play sound
  } else if(G_KeyJustPressed(game, KEY_PRIMARY)) {
    switch (item) {
      case MENU_ITEM_PLAY:
        for(uint8_t i = 6; i < SAVE_SIZE; ++i) {
          game->save[i] = 0;
        }
        if(game->current_level == 0) {
          G_SetGameState(game, GAME_STATE_INTRO);
        } else {
          G_InitLevel(game, game->current_level);
        }
        break;
      case MENU_ITEM_LOAD:
        //TODO
        break;
      case MENU_ITEM_CONTINUE:
        G_SetGameState(game, GAME_STATE_PLAYING);
        break;
      case MENU_ITEM_SOUND:
        //TODO
        break;
      case MENU_ITEM_EXIT:
        game->running = 0;
        break;
      default:
        break;
    }
  } else if(item == MENU_ITEM_PLAY) {
    if(G_KeyRegisters(game, KEY_RIGHT) && (game->current_level < (game->save[0] & 0x0F))) {
      game->current_level++;
      //TODO: play sound
    } else if (G_KeyRegisters(game, KEY_LEFT) && (game->current_level > 0)) {
      game->current_level--;
      //TODO: play sound
    }
  }
}

uint8_t M_GetMenuItem(uint8_t index) {
  uint8_t current_item = 0;
  while (1) { // find first valid item
    // skip non valid items (load if no load available)

    if (index == 0) {
      return (current_item <= MENU_ITEM_EXIT) ? current_item : MENU_ITEM_NONE;
    }
    current_item++;
    index--;
  }
  return MENU_ITEM_NONE;
}