#ifndef LEVEL_H
#define LEVEL_H

#include <stdint.h>

#include "../../../../data/levels.h"

#define NUMBER_OF_LEVELS 1
#define MAX_DOORS 12
#define MAX_ELEMENTS 128
#define MAX_ITEMS MAX_ELEMENTS
#define MAX_ENEMIES 64
#define MAX_PROJECTILES 12

typedef struct doorRecord_s {
  uint8_t coordinates[2];
  /* door state:
  aaaaa: current door height (how open the door is)
  b: currently going up or down
  cc: which key opens door*/
  uint8_t state;// cc b aaaaa
} doorRecord_t;

typedef struct enemyRecord_s {
  uint8_t state;
  uint8_t type;
  uint8_t coordinates[2];
  uint8_t health;
} enemyRecord_t;

typedef struct projectileRecord_s {
  uint8_t type;
  uint8_t double_ftl;
  uint16_t position[3];
  int16_t direction[3];
} projectileRecord_t;

typedef struct currentLevel_s {
  // TODO: level pointer
  uint8_t level_number;
  const uint8_t *textures[7];
  uint32_t time_start;
  uint32_t frame_start;
  uint8_t floor_color;
  uint8_t ceiling_color;

  doorRecord_t door_records[MAX_DOORS];
  uint8_t door_record_count;
  uint8_t door_index;

  uint8_t item_records[MAX_ITEMS];
  uint8_t item_record_count;
  uint8_t item_index;

  enemyRecord_t enemy_records[MAX_ENEMIES];
  uint8_t enemy_record_count;
  uint8_t enemy_index;

  projectileRecord_t projectile_records[MAX_PROJECTILES];
  uint8_t projectile_record_count;
  
  uint8_t boss_count;
  uint8_t enemies_killed;
  uint8_t background_image;
  uint8_t teleporter_count;
  uint16_t fog_mask; // which parts of map have been revealed
  uint8_t item_collision_map[(MAP_SIZE * MAP_SIZE) / 8];
} currentLevel_t;

#endif /* LEVEL_H */