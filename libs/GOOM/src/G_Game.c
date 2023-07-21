#include "GOOM/G_Game.h"

void G_InitGame(game_t *game) {
  game->frame = 0;
  game->frame_time = 0;
  game->current_random = 0;
  game->running = 1;
}

uint8_t G_GameMainLoop(){
  return 1;
}