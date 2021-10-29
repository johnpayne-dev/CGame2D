#pragma once
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef int cgJoystick;

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

int cgJoystickAxis(cgJoystick joystick, int axis);

int cgJoystickAxisCount(cgJoystick joystick);

int cgJoystickButtonCount(cgJoystick joystick);

int cgJoystickConnectionIndex(cgJoystick joystick);

int cgJoystickCount(void);

char * cgJoystickGUID(cgJoystick joystick);

int cgJoystickGamepadAxis(cgJoystick joystick, cgGamepadAxis axis);

bool cgJoystickGamepadIsPressed(cgJoystick joystick, cgGamepadButton button);

cgJoystickHatPosition cgJoystickHatDirection(cgJoystick joystick, int hat);

int cgJoystickHatCount(cgJoystick joystick);

int cgJoystickID(cgJoystick joystick);

void cgJoystickList(cgJoystick * joysticks);

char * cgJoystickName(cgJoystick joystick);

int cgJoystickVibrationStrength(cgJoystick joystick);

bool cgJoystickConnected(cgJoystick joystick);

bool cgJoystickIsPressed(cgJoystick joystick, int button);

bool cgJoystickIsGamepad(cgJoystick joystick);

bool cgJoystickIsVibration(cgJoystick joystick);

void cgJoystickSetVibration(cgJoystick joystick, int left, int right);
