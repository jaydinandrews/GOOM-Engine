#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef enum gamestate_e {
    STATE_INIT = 0,
    STATE_MENU,
    STATE_GAME
} gamestate_e;

typedef struct app_s {
    SDL_Window *window;
    SDL_Surface *window_surface;
    int window_width;
    unsigned int *window_pixels;
    SDL_Surface *raycast_surface;
    unsigned int *raycast_pixels;
    gamestate_e state;
    bool quit;
} app_t;

void I_InitApplication(app_t *app, char *title, unsigned int width, unsigned int height);
void I_QuitApplication();
void I_ChangeState(app_t *app, gamestate_e state);

#endif /* APPLICATION_H */