#include "Keyboard.h"
#include "Event.h"

static bool keyRepeat = true;
static bool textInput = true;
static bool keyDown[cgKeyCount] = { 0 };

static void KeyPressed(cgEventArgs args)
{
	keyDown[args.keyPressed.key] = true;
}

static void KeyReleased(cgEventArgs args)
{
	keyDown[args.keyReleased.key] = false;
}

void cgKeyboardInitialize()
{
	cgEventAddCallback(cgEventKeyPressed, KeyPressed);
	cgEventAddCallback(cgEventKeyReleased, KeyReleased);
}

bool cgKeyboardKeyRepeatEnabled(void)
{
	return keyRepeat;
}

bool cgKeyboardOnScreenSupport()
{
	return SDL_HasScreenKeyboardSupport();
}

bool cgKeyboardTextInputEnabled()
{
	return textInput;
}

bool cgKeyboardIsKeyPressed(cgKey key)
{
	return keyDown[key];
}

void cgKeyboardSetKeyRepeat(bool enable)
{
	keyRepeat = enable;
}

void cgKeyboardSetTextInput(bool enable)
{
	textInput = enable;
}
