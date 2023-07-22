#ifndef APPLICATION_H
#define APPLICATION_H

#include "G_Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <time.h>

typedef struct app_s {
  int running;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Surface *window_surface;
  unsigned int *pixels;
} app_t;

void I_InitApplication(app_t *app, char *title, unsigned int width,
                       unsigned int height);
void I_AppMainLoop(app_t *app, game_t *game);


#endif /* APPLICATION_H */