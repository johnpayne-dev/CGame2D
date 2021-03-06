#pragma once
#include <stdbool.h>

typedef enum cgDisplayOrientation
{
	cgDisplayOrientationUnknown,
	cgDisplayOrientationLandscape,
	cgDisplayOrientationLandscapeFlipped,
	cgDisplayOrientationPortrait,
	cgDisplayOrientationPortraitFlipped,
} cgDisplayOrientation;

typedef struct cgWindowFlags
{
	bool fullscreen;
	bool vsync;
	int msaa;
	bool resizable;
	bool borderless;
	bool highDPI;
} cgWindowFlags;

void cgWindowInitialize(int width, int height, char * title, cgWindowFlags flags);

float cgWindowDPIScale(void);

int cgWindowDisplayIndex(void);

int cgWindowDisplayWidth(int displayIndex);

int cgWindowDisplayHeight(int displayIndex);

int cgWindowDisplayCount(void);

const char * cgWindowDisplayName(int displayIndex);

void cgWindowExitLoop(void);

int cgWindowWidth(void);

int cgWindowHeight(void);

cgWindowFlags cgWindowConfig(void);

cgDisplayOrientation cgWindowDisplayOrientation(int displayIndex);

bool cgWindowIsFullscreen(void);

int cgWindowPositionX(void);

int cgWindowPositionY(void);

const char * cgWindowTitle(void);

bool cgWindowHasKeyboardFocus(void);

bool cgWindowHasMouseFocus(void);

void cgWindowMaximize(void);

void cgWindowMinimize(void);

void cgWindowRestore(void);

bool cgWindowIsRunning(void);

void cgWindowSetFullscreen(bool enable);

void cgWindowSetConfig(cgWindowFlags flags);

void cgWindowSetPosition(int x, int y);

void cgWindowSetTitle(char * title);

void cgWindowSetVsync(bool vsync);

void cgWindowShutdown(void);
