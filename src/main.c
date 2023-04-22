#include <stdlib.h>
#include <GOOM/I_Application.h>

int main(int argc, char *argv[]) {

    app_t app;
    I_InitApplication(&app, "WIP-GAME", 640, 480);
    printf("DEBUG:: SDL_WindowTitle: \'%s\'\n", SDL_GetWindowTitle(app.window));
    int test = 8;
    //init asset manager
    //main menu?

    //game loop

    //quit
}