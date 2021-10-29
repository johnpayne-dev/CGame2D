#pragma once
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef enum cgMouseButton
{
	cgMouseButtonLeft = SDL_BUTTON_LEFT,
	cgMouseButtonMiddle = SDL_BUTTON_MIDDLE,
	cgMouseButtonRight = SDL_BUTTON_RIGHT,
	cgMouseButtonX1 = SDL_BUTTON_X1,
	cgMouseButtonX2 = SDL_BUTTON_X2,
} cgMouseButton;

int cgMousePositionX(void);

int cgMousePositionY(void);

bool cgMouseRelativeMode(void);

bool cgMouseIsPressed(cgMouseButton button);

bool cgMouseIsGrabbed(void);

bool cgMouseIsVisible(void);

void cgMouseSetGrabbed(bool grabbed);

void cgMouseSetPosition(int x, int y);

void cgMouseSetRelativeMode(bool relative);

void cgMouseSetVisible(bool visible);
