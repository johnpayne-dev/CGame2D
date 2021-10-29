#pragma once
#include <SDL2/SDL.h>

typedef struct cgJoystick
{
	int index;
} cgJoystick;

typedef enum cgJoystickHatPosition
{
	cgJoystickHatPositionUp = SDL_HAT_UP,
	cgJoystickHatPositionDown = SDL_HAT_DOWN,
	cgJoystickHatPositionLeft = SDL_HAT_LEFT,
	cgJoystickHatPositionRight = SDL_HAT_RIGHT,
	cgJoystickHatPositionLeftUp = SDL_HAT_LEFTUP,
	cgJoystickHatPositionRightUp = SDL_HAT_RIGHTUP,
	cgJoystickHatPositionLeftDown = SDL_HAT_LEFTDOWN,
	cgJoystickHatPositionRightDown = SDL_HAT_RIGHTDOWN,
	cgJoystickHatPositionCentered = SDL_HAT_CENTERED,
} cgJoystickHatPosition;

typedef enum cgGamepadAxis
{
	cgGamepadAxisLeftX,
	cgGamepadAxisLeftY,
	cgGamepadAxisRightX,
	cgGamepadAxisRightY,
	cgGamepadAxisTriggerLeft,
	cgGamepadAxisTriggerRight,
} cgGamepadAxis;

typedef enum cgGamepadButton
{
	cgGamepadButtonA,
	cgGamepadButtonB,
	cgGamepadButtonX,
	cgGamepadButtonY,
	cgGamepadButtonBack,
	cgGamepadButtonGuide,
	cgGamepadButtonStart,
	cgGamepadButtonLeftStick,
	cgGamepadButtonRightStick,
	cgGamepadButtonLeftShoulder,
	cgGamepadButtonRightShoulder,
	cgGamepadButtonUp,
	cgGamepadButtonDown,
	cgGamepadButtonLeft,
	cgGamepadButtonRight,
} cgGamepadButton;
