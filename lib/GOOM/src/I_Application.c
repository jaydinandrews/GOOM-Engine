#include "I_Application.h"
#include "G_Game.h"



void I_InitApplication(app_t *app, char *title, unsigned int width,
                       unsigned int height) {
  app->running = 1;
  SDL_Init(SDL_INIT_AUDIO);
  app->window =
      SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       width, height, SDL_WINDOW_SHOWN);
  app->renderer = SDL_CreateRenderer(app->window, -1, 0);
  app->texture = SDL_CreateTexture(app->renderer, SDL_PIXELFORMAT_RGB565,
                                   SDL_TEXTUREACCESS_STATIC, width, height);
  app->window_surface = SDL_GetWindowSurface(app->window);
  app->pixels = app->window_surface->pixels;
}

void I_AppMainLoop(app_t *app, game_t *game) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      app->running = 0;
    }
  }

  //if not Game main loop:
    //running = 0
  if(!G_GameMainLoop(game)) {
    app-> running = 0;
  }

  SDL_UpdateTexture(app->texture, NULL, app->pixels, app->window_surface->w * sizeof(uint16_t));
  SDL_RenderClear(app->renderer);
  SDL_RenderCopy(app->renderer, app->texture, NULL, NULL);
  SDL_RenderPresent(app->renderer);
}