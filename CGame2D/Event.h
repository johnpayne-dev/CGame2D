#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "Joystick.h"
#include "Keyboard.h"
#include "Mouse.h"

typedef enum cgEvent
{
	cgEventGamepadAxis,
	cgEventGamepadPressed,
	cgEventGamepadReleased,
	cgEventJoystickAdded,
	cgEventJoystickAxis,
	cgEventJoystickHat,
	cgEventJoystickPressed,
	cgEventJoystickReleased,
	cgEventJoystickRemoved,
	cgEventKeyPressed,
	cgEventKeyReleased,
	cgEventLowMemory,
	cgEventMouseFocused,
	cgEventMouseMoved,
	cgEventMousePressed,
	cgEventMouseReleased,
	cgEventMouseWheelMoved,
	cgEventOnQuit,
	cgEventTextInput,
	cgEventTouchMoved,
	cgEventTouchPressed,
	cgEventTouchReleased,
	cgEventWindowFocused,
	cgEventWindowResized,
	cgEventWindowVisible,
} cgEvent;

typedef union cgEventArgs
{
	struct cgEventGamepadAxisArgs
	{
		cgJoystick joystick;
		cgGamepadAxis axis;
		int value;
	} gamepadAxis;
	struct cgEventGamepadPressedArgs
	{
		cgJoystick joystick;
		cgGamepadButton button;
	} gamepadPressed;
	struct cgEventGamepadReleasedArgs
	{
		cgJoystick joystick;
		cgGamepadButton button;
	} gamepadReleased;
	struct cgEventJoystickAddedArgs
	{
		cgJoystick joystick;
	} joystickAdded;
	struct cgEventJoystickAxisArgs
	{
		cgJoystick joystick;
		int axis;
		int value;
	} joystickAxis;
	struct cgEventJoystickHatArgs
	{
		cgJoystick joystick;
		int hat;
		cgJoystickHatPosition position;
	} joystickHat;
	struct cgEventJoystickPressedArgs
	{
		cgJoystick joystick;
		int button;
	} joystickPressed;
	struct cgEventJoystickReleasedArgs
	{
		cgJoystick joystick;
		int button;
	} joystickReleased;
	struct cgEventJoystickRemovedArgs
	{
		cgJoystick joystick;
	} joystickRemoved;
	struct cgEventKeyPressedArgs
	{
		cgKey key;
		bool repeat;
	} keyPressed;
	struct cgEventKeyReleasedArgs
	{
		cgKey key;
	} keyReleased;
	struct cgEventMouseFocusedArgs
	{
		bool focused;
	} mouseFocused;
	struct cgEventMouseMovedArgs
	{
		int x, y;
		int dx, dy;
		bool isTouch;
	} mouseMoved;
	struct cgEventMousePressedArgs
	{
		int x, y;
		cgMouseButton button;
		bool isTouch;
	} mousePressed;
	struct cgEventMouseReleasedArgs
	{
		int x, y;
		cgMouseButton button;
		bool isTouch;
	} mouseReleased;
	struct cgEventMouseWheelMovedArgs
	{
		int x, y;
	} mouseWheelMoved;
	struct cgEventTextInputArgs
	{
		char * text;
	} textInput;
	struct cgEventTouchMovedArgs
	{
		int id;
		int x, y;
		int dx, dy;
		int pressure;
	} touchMoved;
	struct cgEventTouchPressedArgs
	{
		int id;
		int x, y;
		int dx, dy;
		int pressure;
	} touchPressed;
	struct cgEventTouchReleasedArgs
	{
		int id;
		int x, y;
		int dx, dy;
		int pressure;
	} touchReleased;
	struct cgEventWindowFocusedArgs
	{
		bool focused;
	} windowFocused;
	struct cgEventWindowResizedArgs
	{
		int width, height;
	} windowResized;
	struct cgEventWindowVisibleArgs
	{
		bool visible;
	} windowVisible;
} cgEventArgs;

typedef void (*cgEventCallback)(cgEventArgs);

void cgEventAddCallback(cgEvent event, cgEventCallback callback);

void cgEventClear(void);

void cgEventPoll(void);

void cgEventPush(cgEvent event, cgEventArgs args);

void cgEventQuit(void);

void cgEventRemoveCallback(cgEvent event, cgEventCallback callback);
