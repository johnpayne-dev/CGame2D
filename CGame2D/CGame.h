#pragma once
#include "Event.h"
#include "Joystick.h"
#include "Keyboard.h"
#include "List.h"
#include "Log.h"
#include "Mouse.h"
#include "Window.h"

void cgInitialize(int width, int height, char * title, cgWindowFlags flags);

void cgShutdown(void);
