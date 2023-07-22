#include "settings.h"

#include "GOOM/I_Application.h"
#include "GOOM/G_Game.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

int main(int argc, char *argv[]) {

  app_t app;
  I_InitApplication(&app, "WIP-GAME", WINDOW_WIDTH, WINDOW_HEIGHT);

  game_t game;
  G_InitGame(&game);

  // keyboard state
  // controller open
  // audio

  // show cursor
  // PumpEvents
  // Game Controller Update

  SDL_PumpEvents();
  while (app.running) {
    I_AppMainLoop(&app, &game);
  }

  // close controller
  // pause audio - close audio

  SDL_DestroyTexture(app.texture);
  SDL_DestroyRenderer(app.renderer);
  SDL_DestroyWindow(app.window);

  return 0;
}