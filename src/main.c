#include "GOOM/G_Game.h"
#include "GOOM/I_Application.h"

int main(int argc, char *argv[]) {

  app_t app;
  I_InitApplication(&app, "WIP-GAME", 640, 480);
  // init asset manager
  // main menu?

  //G_InitGame(); // main menu?

  // game loop
  while (!app.quit) {
    G_MainLoop(&app);
  }

  // quit
  I_QuitApplication(&app);
  return 0;
}
