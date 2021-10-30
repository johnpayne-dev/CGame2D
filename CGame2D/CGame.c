#include <SDL2/SDL.h>
#include "CGame.h"

void cgInitialize(int width, int height, char * title, cgWindowFlags flags)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	cgWindowInitialize(width, height, title, flags);
	cgEventInitialize();
	cgKeyboardInitialize();
}

void cgShutdown()
{
	cgEventShutdown();
	cgWindowShutdown();
	SDL_Quit();
}
