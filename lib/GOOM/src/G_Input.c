#include "G_Input.h"

uint16_t G_KeyRegisters(game_t *game, uint8_t key) {
  return G_KeyJustPressed(game, key) || G_KeyRepeated(game, key);
}

uint8_t G_KeyJustPressed(game_t *game, uint8_t key) {
  return (game->key_state[key]) == 1;
}

uint8_t G_KeyRepeated(game_t *game, uint8_t key) {
  //TODO
  return 0;
}