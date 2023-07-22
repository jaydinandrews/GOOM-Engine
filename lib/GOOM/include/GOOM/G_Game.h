#ifndef GAME_H
#define GAME_H

#include "G_Settings.h"
#include <stdint.h>
#include <SDL2/SDL_timer.h>

#define GAME_STATE_INIT 0
#define GAME_STATE_MENU 1

#define KEY_COUNT 16
#define MS_PER_FRAME (1000 / TARGET_FPS)

typedef struct game_s {

  uint8_t state; // current game state
  uint32_t state_time; // time since last state change
  uint8_t key_state[KEY_COUNT];

  uint32_t frame; // current frame number
  uint32_t frame_time; // time of current frame start
  uint8_t current_random; // seed for RNG
  uint8_t running; // whether game continues or exits

  uint16_t ray_constraint_max_hits;
  uint16_t ray_constraint_max_steps;
  uint16_t visibility_ray_constraint_max_hits;
  uint16_t visibility_ray_constraint_max_steps;

  uint8_t selected_menu_item;
} game_t;

void G_InitGame(game_t *game);
void G_SetGameState(game_t *game, uint8_t state);
uint8_t G_GameMainLoop(game_t *game);
void G_GameStep(game_t *game);

#endif /* GAME_H */