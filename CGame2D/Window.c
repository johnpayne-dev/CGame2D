#include <SDL2/SDL.h>
#include "Window.h"
#include "Log.h"

static struct
{
	SDL_Window * pointer;
	SDL_GLContext * context;
	int width, height;
	char * title;
	cgWindowFlags config;
	bool running;
} window;

void cgWindowInitialize(int width, int height, char * title, cgWindowFlags config)
{
	SDL_Init(SDL_INIT_VIDEO);
	window.width = width;
	window.height = height;
	window.title = title;
	window.config = config;
	
	uint32_t flags = SDL_WINDOW_OPENGL;
	flags |= config.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
	flags |= config.resizable ? SDL_WINDOW_RESIZABLE : 0;
	flags |= config.borderless ? SDL_WINDOW_BORDERLESS : 0;
	flags |= config.highDPI ? SDL_WINDOW_ALLOW_HIGHDPI : 0;
	
	window.pointer = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	if (window.pointer == NULL) { cgLogFatal("Failed to create the window: %s\n", SDL_GetError()); }
	SDL_GetWindowSize(window.pointer, &window.width, &window.height);
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, config.msaa);
	
	window.context = SDL_GL_CreateContext(window.pointer);
	if (window.context == NULL) { cgLogFatal("Failed to create the context: %s\n", SDL_GetError()); }
	
	SDL_GL_SetSwapInterval(config.vsync ? 1 : 0);
}

float cgWindowDPIScale()
{
	int w = 0;
	SDL_GL_GetDrawableSize(window.pointer, &w, &(int){ 0 });
	return w / window.width;
}

int cgWindowDisplayIndex()
{
	return SDL_GetWindowDisplayIndex(window.pointer);
}

int cgWindowDisplayWidth(int displayIndex)
{
	SDL_Rect rect = { 0 };
	SDL_GetDisplayBounds(displayIndex, &rect);
	return rect.w;
}

int cgWindowDisplayHeight(int displayIndex)
{
	SDL_Rect rect = { 0 };
	SDL_GetDisplayBounds(displayIndex, &rect);
	return rect.h;
}

int cgWindowDisplayCount()
{
	return SDL_GetNumVideoDisplays();
}

const char * cgWindowDisplayName(int displayIndex)
{
	return SDL_GetDisplayName(displayIndex);
}

void cgWindowExitLoop()
{
	window.running = false;
}

int cgWindowWidth()
{
	return window.width;
}

int cgWindowHeight()
{
	return window.height;
}

cgWindowFlags cgWindowConfig()
{
	return window.config;
}

cgDisplayOrientation cgWindowDisplayOrientation(int displayIndex)
{
	return (cgDisplayOrientation)SDL_GetDisplayOrientation(displayIndex);
}

bool cgWindowIsFullscreen()
{
	return window.config.fullscreen;
}

int cgWindowPositionX()
{
	int x = 0;
	SDL_GetWindowPosition(window.pointer, &x, &(int){ 0 });
	return x;
}

int cgWindowPositionY()
{
	int y = 0;
	SDL_GetWindowPosition(window.pointer, &(int){ 0 }, &y);
	return y;
}

const char * cgWindowTitle()
{
	return SDL_GetWindowTitle(window.pointer);
}

bool cgWindowHasKeyboardFocus()
{
	return SDL_GetKeyboardFocus() == window.pointer;
}

bool cgWindowHasMouseFocus()
{
	return SDL_GetMouseFocus() == window.pointer;
}

void cgWindowMaximize()
{
	SDL_MaximizeWindow(window.pointer);
}

void cgWindowMinimize()
{
	SDL_MinimizeWindow(window.pointer);
}

void cgWindowRestore()
{
	SDL_RestoreWindow(window.pointer);
}

bool cgWindowIsRunning()
{
	return window.running;
}

void cgWindowSetFullscreen(bool enable)
{
	SDL_SetWindowFullscreen(window.pointer, enable ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

void cgWindowSetConfig(cgWindowFlags flags)
{
	cgWindowSetFullscreen(flags.fullscreen);
	SDL_SetWindowResizable(window.pointer, flags.resizable);
	SDL_SetWindowBordered(window.pointer, !flags.borderless);
	SDL_GL_SetSwapInterval(flags.vsync ? 1 : 0);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, flags.msaa);
	window.config = flags;
}

void cgWindowSetPosition(int x, int y)
{
	SDL_SetWindowPosition(window.pointer, x, y);
}

void cgWindowSetTitle(char * title)
{
	SDL_SetWindowTitle(window.pointer, title);
}

void cgWindowSetVsync(bool vsync)
{
	SDL_GL_SetSwapInterval(vsync ? 1 : 0);
}
