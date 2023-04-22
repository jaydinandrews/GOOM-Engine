#include "I_Application.h"
#include "R_Renderer.h"

int R_PROJECTION_WIDTH, R_PROJECTION_HEIGHT, R_PROJECTION_CENTER,
    R_PROJECTION_DISTANCE, R_MAX_VERTICAL, R_MIN_VERTICAL;
uint32_t R_BLANK_COLOR;

void R_InitRenderer(app_t *app) {
    //set colors
    R_BLANK_COLOR = SDL_MapRGB(app->window_surface->format, 0, 0, 0);
    //set graphics
    R_PROJECTION_WIDTH = 320;
    R_PROJECTION_HEIGHT = 240;
    R_PROJECTION_CENTER = 120;
    R_PROJECTION_DISTANCE = 277;
    R_MAX_VERTICAL = 25;
    R_MIN_VERTICAL = -25;

    if(app->raycast_surface != NULL) {
        SDL_FreeSurface(app->raycast_surface);
    }
    app->raycast_surface = SDL_CreateRGBSurfaceWithFormat(0,
                            R_PROJECTION_WIDTH, R_PROJECTION_HEIGHT, 32, app->window_surface->format->format);
    app->raycast_pixels = app->raycast_surface->pixels;
    //clear renderer
    R_ClearRenderer(app);
}

void R_ClearRenderer(app_t *app) {
    for(int y = 0; y < R_PROJECTION_HEIGHT; y++){
        for(int x = 0; x < R_PROJECTION_WIDTH; x++){
            app->raycast_pixels[x + (y * app->raycast_surface->w)] = R_BLANK_COLOR;
        }
    }
}