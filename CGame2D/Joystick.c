#include <SDL2/SDL.h>
#include "Joystick.h"

int cgJoystickAxisCount(cgJoystick joystick)
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	int value = SDL_JoystickNumAxes(joy);
	SDL_JoystickClose(joy);
	return value;
}

int16_t cgJoystickAxisValue(cgJoystick joystick, uint8_t axis)
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	int16_t value = SDL_JoystickGetAxis(joy, axis);
	SDL_JoystickClose(joy);
	return value;
}

int cgJoystickButtonCount(cgJoystick joystick)
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	int value = SDL_JoystickNumButtons(joy);
	SDL_JoystickClose(joy);
	return value;
}

bool cgJoystickConnected(cgJoystick joystick)
{
	return cgJoystickConnectionIndex(joystick) != -1;
}

int cgJoystickConnectionIndex(cgJoystick joystick)
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	int value = SDL_JoystickGetPlayerIndex(joy);
	SDL_JoystickClose(joy);
	return value;
}

int cgJoystickCount()
{
	return SDL_NumJoysticks();
}

cgJoystick cgJoystickFromConnectionIndex(int32_t index)
{
	SDL_Joystick * joystick = SDL_JoystickFromPlayerIndex(index);
	cgJoystick instance = SDL_JoystickInstanceID(joystick);
	SDL_JoystickClose(joystick);
	return instance;
}

void cgJoystickGUID(cgJoystick joystick, uint8_t guid[16])
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	memcpy(guid, SDL_JoystickGetGUID(joy).data, 16);
	SDL_JoystickClose(joy);
}

int cgJoystickHatCount(cgJoystick joystick)
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	int value = SDL_JoystickNumHats(joy);
	SDL_JoystickClose(joy);
	return value;
}

cgJoystickHatPosition cgJoystickHatDirection(cgJoystick joystick, uint8_t hat)
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	cgJoystickHatPosition value = SDL_JoystickGetHat(joy, hat);
	SDL_JoystickClose(joy);
	return value;
}

bool cgJoystickIsGamepad(cgJoystick joystick)
{
	SDL_GameController * controller = SDL_GameControllerFromInstanceID(joystick);
	bool value = controller != NULL;
	SDL_GameControllerClose(controller);
	return value;
}

bool cgJoystickIsPressed(cgJoystick joystick, uint8_t button)
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	bool value = SDL_JoystickGetButton(joy, button);
	SDL_JoystickClose(joy);
	return value;
}

void cgJoystickList(cgJoystick * joysticks)
{
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		SDL_Joystick * joy = SDL_JoystickOpen(i);
		joysticks[i] = SDL_JoystickInstanceID(joy);
		SDL_JoystickClose(joy);
	}
}

const char * cgJoystickName(cgJoystick joystick)
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	const char * value = SDL_JoystickName(joy);
	SDL_JoystickClose(joy);
	return value;
}

void cgJoystickVibrate(cgJoystick joystick, uint16_t left, uint16_t right, uint32_t ms)
{
	SDL_Joystick * joy = SDL_JoystickFromInstanceID(joystick);
	SDL_JoystickRumbleTriggers(joy, left, right, ms);
	SDL_JoystickClose(joy);
}

int16_t cgGamepadAxisValue(cgJoystick joystick, cgGamepadAxis axis)
{
	SDL_GameController * controller = SDL_GameControllerFromInstanceID(joystick);
	int16_t value = SDL_GameControllerGetAxis(controller, (SDL_GameControllerAxis)axis);
	SDL_GameControllerClose(controller);
	return value;
}

bool cgGamepadIsPressed(cgJoystick joystick, cgGamepadButton button)
{
	SDL_GameController * joy = SDL_GameControllerFromInstanceID(joystick);
	bool value = SDL_GameControllerGetButton(joy, (SDL_GameControllerButton)button);
	SDL_GameControllerClose(joy);
	return value;
}
