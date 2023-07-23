#ifndef GAME_H
#define GAME_H

#include "G_Settings.h"
#include "G_Level.h"

#include <stdint.h>
#include <SDL2/SDL_timer.h>

#define GAME_STATE_INIT 0
#define GAME_STATE_MENU 1
#define GAME_STATE_INTRO 2
#define GAME_STATE_PLAYING 3

#define KEY_COUNT 16
#define SAVE_SIZE 12

#define MS_PER_FRAME (1000 / TARGET_FPS)

typedef struct game_s {

  uint8_t state; // current game state
  uint32_t state_time; // time since last state change
  uint8_t key_state[KEY_COUNT]; // state all input keys
  uint8_t current_menu_item; // current item when in GAME_STATE_MENU
  uint8_t current_menu_level; // current level number when in GAME_STATE_MENU

  currentLevel_t current_level;

  uint32_t frame; // current frame number
  uint32_t frame_time; // time of current frame start
  uint8_t current_random; // seed for RNG
  uint8_t running; // whether game continues or exits

  uint16_t ray_constraint_max_hits;
  uint16_t ray_constraint_max_steps;
  uint16_t visibility_ray_constraint_max_hits;
  uint16_t visibility_ray_constraint_max_steps;

  uint8_t save[SAVE_SIZE];
} game_t;

void G_InitGame(game_t *game);
void G_SetGameState(game_t *game, uint8_t state);
uint8_t G_GameMainLoop(game_t *game);
void G_GameStep(game_t *game);
void G_GameStepPlaying(game_t *game);
void G_InitLevel(game_t *game, uint8_t level_number);

#endif /* GAME_H */