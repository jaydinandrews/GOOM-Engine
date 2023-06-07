#include "GOOM/I_Application.h"
#include "GOOM/R_Renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <time.h>

void I_InitApplication(app_t *app, char *title, unsigned int width,
                       unsigned int height) {
  app->quit = false;
  SDL_Init(SDL_INIT_EVERYTHING);
  uint32_t window_flags = 0;
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
  app->window =
      SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       width, height, window_flags);
  app->window_surface = SDL_GetWindowSurface(app->window);
  app->window_width = app->window_surface->w;
  app->window_pixels = app->window_surface->pixels;

  R_InitRenderer(app);
  I_ChangeState(app, STATE_GAME);
}

void I_QuitApplication(app_t *app) {
  SDL_FreeSurface(app->raycast_surface);
  SDL_FreeSurface(app->window_surface);
  SDL_DestroyWindow(app->window);
  SDL_Quit();
}

void I_ChangeState(app_t *app, gamestate_e state) {
  app->state = state;
  // relative mouse mode??
}