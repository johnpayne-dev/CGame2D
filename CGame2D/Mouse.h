#pragma once
#include <stdbool.h>

typedef enum cgMouseButton
{
	cgMouseButtonLeft = 1,
	cgMouseButtonMiddle = 2,
	cgMouseButtonRight = 3,
	cgMouseButtonX1 = 4,
	cgMouseButtonX2 = 5,
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
