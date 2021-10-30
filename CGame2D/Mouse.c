#include "Mouse.h"
#include "Window.h"

static bool grabbed = false;
static bool visible = true;

int cgMousePositionX()
{
	int x = 0;
	SDL_GetMouseState(&x, &(int){ 0 });
	return x;
}

int cgMousePositionY()
{
	int y = 0;
	SDL_GetMouseState(&(int){ 0 }, &y);
	return y;
}

bool cgMouseRelativeMode()
{
	return SDL_GetRelativeMouseMode();
}

bool cgMouseIsPressed(cgMouseButton button)
{
	return SDL_GetMouseState(&(int){ 0 }, &(int){ 0 }) & button;
}

bool cgMouseIsGrabbed()
{
	return grabbed;
}

bool cgMouseIsVisible()
{
	return visible;
}

void cgMouseSetGrabbed(bool enable)
{
	grabbed = enable;
	SDL_CaptureMouse(enable);
}

void cgMouseSetPosition(int x, int y)
{
	SDL_WarpMouseGlobal(cgWindowPositionX() + x, cgWindowPositionY() + y);
}

void cgMouseSetRelativeMode(bool relative)
{
	SDL_SetRelativeMouseMode(relative);
}

void cgMouseSetVisible(bool enable)
{
	visible = enable;
	SDL_ShowCursor(enable);
}
