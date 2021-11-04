#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef int cgJoystick;

typedef enum cgJoystickHatPosition
{
	cgJoystickHatPositionCentered = 0x0,
	cgJoystickHatPositionUp = 0x01,
	cgJoystickHatPositionDown = 0x04,
	cgJoystickHatPositionLeft = 0x08,
	cgJoystickHatPositionRight = 0x02,
	cgJoystickHatPositionLeftUp = 0x09,
	cgJoystickHatPositionRightUp = 0x03,
	cgJoystickHatPositionLeftDown = 0x0C,
	cgJoystickHatPositionRightDown = 0x06,
} cgJoystickHatPosition;

typedef enum cgGamepadAxis
{
	cgGamepadAxisLeftX,
	cgGamepadAxisLeftY,
	cgGamepadAxisRightX,
	cgGamepadAxisRightY,
	cgGamepadAxisTriggerLeft,
	cgGamepadAxisTriggerRight,
	cgGamepadAxisInvalid = -1,
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
	cgGamepadButtonMisc1,
	cgGamepadButtonInvalid = -1,
} cgGamepadButton;

int cgJoystickAxisCount(cgJoystick joystick);

int16_t cgJoystickAxisValue(cgJoystick joystick, uint8_t axis);

int cgJoystickButtonCount(cgJoystick joystick);

bool cgJoystickConnected(cgJoystick joystick);

int cgJoystickConnectionIndex(cgJoystick joystick);

int cgJoystickCount(void);

cgJoystick cgJoystickFromConnectionIndex(int32_t index);

void cgJoystickGUID(cgJoystick joystick, uint8_t guid[16]);

cgJoystickHatPosition cgJoystickHatDirection(cgJoystick joystick, uint8_t hat);

int cgJoystickHatCount(cgJoystick joystick);

bool cgJoystickIsGamepad(cgJoystick joystick);

bool cgJoystickIsPressed(cgJoystick joystick, uint8_t button);

void cgJoystickList(cgJoystick * joysticks);

const char * cgJoystickName(cgJoystick joystick);

int16_t cgGamepadAxisValue(cgJoystick joystick, cgGamepadAxis axis);

bool cgGamepadIsPressed(cgJoystick joystick, cgGamepadButton button);
