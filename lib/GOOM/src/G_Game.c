#include "G_Game.h"
#include "G_Input.h"
#include "M_Menu.h"

void G_InitGame(game_t *game) {
  game->frame = 0;
  game->frame_time = 0;
  game->current_random = 0;
  game->running = 1;

  game->ray_constraint_max_hits = RAYCAST_MAX_HITS;
  game->ray_constraint_max_steps = RAYCAST_MAX_STEPS;
  game->visibility_ray_constraint_max_hits = RAYCAST_VISIBILITY_MAX_HITS;
  game->visibility_ray_constraint_max_steps = RAYCAST_VISIBILITY_MAX_STEPS;

  // Average texture colors
  // Background scale map
  // Key state
  // Try to load saved game
  // Set music on/off
  G_SetGameState(game, GAME_STATE_INIT);
}

void G_SetGameState(game_t *game, uint8_t state) {
  game->state = state;
  game->state_time = 0;
}

uint8_t G_GameMainLoop(game_t *game) {
  if (game->state != GAME_STATE_INIT) {
    uint32_t time_current = SDL_GetTicks();
    int32_t time_since_last_frame = time_current - game->frame_time;
    if (time_since_last_frame >= MS_PER_FRAME) {
      uint8_t steps = 0;
      uint8_t was_first_frame = game->frame == 0;
      while (time_since_last_frame >= MS_PER_FRAME) {
        // get current weapon
        game->frame_time += MS_PER_FRAME;
        G_GameStep(game);
        // check and/or set new weapon
        time_since_last_frame -= MS_PER_FRAME;
        game->frame++;
        steps++;
      }
      // if((steps > 1) && (!was_first_frame)) then failed to reach target fps
      //  TODO: Draw
    }      // else: wait and relieve CPU
  } else { // if in GAME_STATE_INIT
    G_SetGameState(game, GAME_STATE_MENU);
  }
  return game->running;
}

void G_GameStep(game_t *game) {
  //TODO: get key state for changes

  switch(game->state) {
    case GAME_STATE_PLAYING:
      G_GameStepPlaying(game);
      break;
    case GAME_STATE_MENU:
      M_GameStepMenu(game);
      break;
    default:
      break;
  }
  game->state_time += MS_PER_FRAME;
}

void G_GameStepPlaying(game_t *game) {
  if(G_KeyIsDown(game, KEY_MENU)) {
    G_SetGameState(game, GAME_STATE_MENU);
    //TODO: play sound
    return;
  }

  G_UpdateLevel();

}

void G_InitLevel(game_t *game, uint8_t level_number) {
  //TODO
}