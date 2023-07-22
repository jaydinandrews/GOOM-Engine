#ifndef GAME_H
#define GAME_H

#include <stdint.h>

typedef struct game_s {

  uint32_t frame; // current frame number
  uint32_t frame_time; // time of current frame start
  uint8_t current_random; // seed for RNG
  uint8_t running; // whether game continues or exits
} game_t;

void G_InitGame(game_t *game);

uint8_t G_GameMainLoop();

#endif /* GAME_H */