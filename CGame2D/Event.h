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
	cgEventCount,
} cgEvent;

typedef union cgEventArgs
{
	struct cgEventGamepadAxisArgs
	{
		cgJoystick joystick;
		cgGamepadAxis axis;
		int16_t value;
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
		int32_t connectionIndex;
	} joystickAdded;
	struct cgEventJoystickAxisArgs
	{
		cgJoystick joystick;
		uint8_t axis;
		int16_t value;
	} joystickAxis;
	struct cgEventJoystickHatArgs
	{
		cgJoystick joystick;
		uint8_t hat;
		cgJoystickHatPosition position;
	} joystickHat;
	struct cgEventJoystickPressedArgs
	{
		cgJoystick joystick;
		uint8_t button;
	} joystickPressed;
	struct cgEventJoystickReleasedArgs
	{
		cgJoystick joystick;
		uint8_t button;
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
		int32_t x, y;
		int32_t dx, dy;
		bool isTouch;
	} mouseMoved;
	struct cgEventMousePressedArgs
	{
		int32_t x, y;
		cgMouseButton button;
		bool isTouch;
	} mousePressed;
	struct cgEventMouseReleasedArgs
	{
		int32_t x, y;
		cgMouseButton button;
		bool isTouch;
	} mouseReleased;
	struct cgEventMouseWheelMovedArgs
	{
		int32_t x, y;
	} mouseWheelMoved;
	struct cgEventTextInputArgs
	{
		char * text;
	} textInput;
	struct cgEventTouchMovedArgs
	{
		int64_t touchID;
		int64_t fingerID;
		float x, y;
		float dx, dy;
		float pressure;
	} touchMoved;
	struct cgEventTouchPressedArgs
	{
		int64_t touchID;
		int64_t fingerID;
		float x, y;
		float dx, dy;
		float pressure;
	} touchPressed;
	struct cgEventTouchReleasedArgs
	{
		int64_t touchID;
		int64_t fingerID;
		float x, y;
		float dx, dy;
		float pressure;
	} touchReleased;
	struct cgEventWindowFocusedArgs
	{
		bool focused;
	} windowFocused;
	struct cgEventWindowResizedArgs
	{
		int32_t width, height;
	} windowResized;
	struct cgEventWindowVisibleArgs
	{
		bool visible;
	} windowVisible;
} cgEventArgs;

typedef void (*cgEventCallback)(cgEventArgs);

void cgEventInitialize(void);

void cgEventAddCallback(cgEvent event, cgEventCallback callback);

void cgEventClear(void);

void cgEventPoll(void);

void cgEventPush(cgEvent event, cgEventArgs args);

void cgEventQuit(void);

void cgEventRemoveCallback(cgEvent event, cgEventCallback callback);
