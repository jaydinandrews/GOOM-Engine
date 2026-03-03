#include "R_Render.h"

#define BACKGROUND_SCALE (SCREEN_RESOLUTION_X / (4 * TEXTURE_SIZE))

void R_Draw(game_t *game) {
  switch (game->state) {
  case GAME_STATE_MENU:
    R_DrawMenu(game);
    return;
  case GAME_STATE_INTRO:
    break;
  default:
    break;
  }
}