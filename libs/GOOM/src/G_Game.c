#include "GOOM/G_Game.h"
#include "I_Application.h"

void G_MainLoop(app_t *app) {
  switch (app->state) {
  case STATE_INIT:
    break;
  case STATE_MENU:
    break;
  case STATE_GAME:
    G_GameLoop(app);
    break;
  default:
    break;
  }
}

void G_GameLoop(app_t *app) {
    return;
}