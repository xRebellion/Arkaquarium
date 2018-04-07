#include "Mouse.hpp"

bool leftMouseButtonPressed()
{
    return SDL_GetMouseState(NULL,NULL) && SDL_BUTTON(SDL_BUTTON_LEFT);
}

bool rightMouseButtonPressed()
{
    return SDL_GetMouseState(NULL,NULL) && SDL_BUTTON(SDL_BUTTON_RIGHT);
}