#include <SDL2/SDL.h>
#include "Event.h"
#include "List.h"
#include "Window.h"

static cgList(cgEventCallback) callbacks[cgEventCount];

void cgEventInitialize()
{
	for (int i = 0; i < cgEventCount; i++)
	{
		callbacks[i] = cgListCreate(sizeof(cgEventCallback));
	}
	SDL_Init(SDL_INIT_EVENTS);
}

void cgEventAddCallback(cgEvent event, cgEventCallback callback)
{
	callbacks[event] = cgListPush(callbacks[event], &callback);
}

void cgEventClear()
{
	while (SDL_PollEvent(&(SDL_Event){ 0 }));
}

void cgEventPoll()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_CONTROLLERAXISMOTION:
				for (int i = 0; i < cgListLength(callbacks[cgEventGamepadAxis]); i++)
				{
					callbacks[cgEventGamepadAxis][i]((cgEventArgs){ .gamepadAxis = { .joystick = event.caxis.which, .axis = event.caxis.axis, .value = event.caxis.value } });
				}
				break;
			case SDL_CONTROLLERBUTTONDOWN:
				for (int i = 0; i < cgListLength(callbacks[cgEventGamepadPressed]); i++)
				{
					callbacks[cgEventGamepadPressed][i]((cgEventArgs){ .gamepadPressed = { .joystick = event.cbutton.which, .button = event.cbutton.button } });
				}
				break;
			case SDL_CONTROLLERBUTTONUP:
				for (int i = 0; i < cgListLength(callbacks[cgEventGamepadReleased]); i++)
				{
					callbacks[cgEventGamepadReleased][i]((cgEventArgs){ .gamepadReleased = { .joystick = event.cbutton.which, .button = event.cbutton.button } });
				}
				break;
			case SDL_JOYDEVICEADDED:
				for (int i = 0; i < cgListLength(callbacks[cgEventJoystickAdded]); i++)
				{
					callbacks[cgEventJoystickAdded][i]((cgEventArgs){ .joystickAdded = { .connectionIndex = SDL_JoystickGetDevicePlayerIndex(event.jdevice.which) } });
				}
				break;
			case SDL_JOYAXISMOTION:
				for (int i = 0; i < cgListLength(callbacks[cgEventJoystickAxis]); i++)
				{
					callbacks[cgEventJoystickAxis][i]((cgEventArgs){ .joystickAxis = { .joystick = event.jaxis.which, .axis = event.jaxis.axis, .value = event.jaxis.value } });
				}
				break;
			case SDL_JOYHATMOTION:
				for (int i = 0; i < cgListLength(callbacks[cgEventJoystickHat]); i++)
				{
					callbacks[cgEventJoystickHat][i]((cgEventArgs){ .joystickHat = { .joystick = event.jhat.which, .hat = event.jhat.hat, .position = event.jhat.value } });
				}
				break;
			case SDL_JOYBUTTONDOWN:
				for (int i = 0; i < cgListLength(callbacks[cgEventJoystickPressed]); i++)
				{
					callbacks[cgEventJoystickPressed][i]((cgEventArgs){ .joystickPressed = { .joystick = event.jbutton.which, .button = event.jbutton.button } });
				}
				break;
			case SDL_JOYBUTTONUP:
				for (int i = 0; i < cgListLength(callbacks[cgEventJoystickReleased]); i++)
				{
					callbacks[cgEventJoystickReleased][i]((cgEventArgs){ .joystickReleased = { .joystick = event.jbutton.which, .button = event.jbutton.button } });
				}
				break;
			case SDL_JOYDEVICEREMOVED:
				for (int i = 0; i < cgListLength(callbacks[cgEventJoystickRemoved]); i++)
				{
					callbacks[cgEventJoystickRemoved][i]((cgEventArgs){ .joystickRemoved = { .joystick = event.jdevice.which } });
				}
				break;
			case SDL_KEYDOWN:
				for (int i = 0; i < cgListLength(callbacks[cgEventKeyPressed]); i++)
				{
					callbacks[cgEventKeyPressed][i]((cgEventArgs){ .keyPressed = { .key = (cgKey)event.key.keysym.scancode, .repeat = event.key.repeat } });
				}
				break;
			case SDL_KEYUP:
				for (int i = 0; i < cgListLength(callbacks[cgEventKeyReleased]); i++)
				{
					callbacks[cgEventKeyReleased][i]((cgEventArgs){ .keyReleased = { .key = (cgKey)event.key.keysym.scancode } });
				}
				break;
			case SDL_APP_LOWMEMORY:
				for (int i = 0; i < cgListLength(callbacks[cgEventLowMemory]); i++)
				{
					callbacks[cgEventLowMemory][i]((cgEventArgs){ 0 });
				}
				break;
			case SDL_MOUSEMOTION:
				for (int i = 0; i < cgListLength(callbacks[cgEventMouseMoved]); i++)
				{
					callbacks[cgEventMouseMoved][i]((cgEventArgs){ .mouseMoved = { .x = event.motion.x, .y = event.motion.y, .dx = event.motion.xrel, .dy = event.motion.yrel, .isTouch = event.motion.which == SDL_TOUCH_MOUSEID } });
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				for (int i = 0; i < cgListLength(callbacks[cgEventMousePressed]); i++)
				{
					callbacks[cgEventMousePressed][i]((cgEventArgs){ .mousePressed = { .x = event.button.x, .y = event.button.y, .button = event.button.button, .isTouch = event.button.which == SDL_TOUCH_MOUSEID } });
				}
				break;
			case SDL_MOUSEBUTTONUP:
				for (int i = 0; i < cgListLength(callbacks[cgEventMouseReleased]); i++)
				{
					callbacks[cgEventMouseReleased][i]((cgEventArgs){ .mouseReleased = { .x = event.button.x, .y = event.button.y, .button = event.button.button, .isTouch = event.button.which == SDL_TOUCH_MOUSEID } });
				}
				break;
			case SDL_MOUSEWHEEL:
				for (int i = 0; i < cgListLength(callbacks[cgEventMouseWheelMoved]); i++)
				{
					callbacks[cgEventMouseWheelMoved][i]((cgEventArgs){ .mouseWheelMoved = { .x = event.wheel.x, .y = event.wheel.y } });
				}
				break;
			case SDL_QUIT:
				for (int i = 0; i < cgListLength(callbacks[cgEventOnQuit]); i++)
				{
					callbacks[cgEventOnQuit][i]((cgEventArgs){ 0 });
				}
				cgWindowExitLoop();
				break;
			case SDL_TEXTINPUT:
				for (int i = 0; i < cgListLength(callbacks[cgEventTextInput]); i++)
				{
					callbacks[cgEventTextInput][i]((cgEventArgs){ .textInput = { .text = event.text.text } });
				}
				break;
			case SDL_FINGERMOTION:
				for (int i = 0; i < cgListLength(callbacks[cgEventTouchMoved]); i++)
				{
					callbacks[cgEventTouchMoved][i]((cgEventArgs){ .touchMoved = { .touchID = event.tfinger.touchId, .fingerID = event.tfinger.fingerId, .x = event.tfinger.x, .y = event.tfinger.y, .dx = event.tfinger.dx, .dy = event.tfinger.dy, .pressure = event.tfinger.pressure } });
				}
				break;
			case SDL_FINGERDOWN:
				for (int i = 0; i < cgListLength(callbacks[cgEventTouchPressed]); i++)
				{
					callbacks[cgEventTouchPressed][i]((cgEventArgs){ .touchPressed = { .touchID = event.tfinger.touchId, .fingerID = event.tfinger.fingerId, .x = event.tfinger.x, .y = event.tfinger.y, .dx = event.tfinger.dx, .dy = event.tfinger.dy, .pressure = event.tfinger.pressure } });
				}
				break;
			case SDL_FINGERUP:
				for (int i = 0; i < cgListLength(callbacks[cgEventTouchReleased]); i++)
				{
					callbacks[cgEventTouchReleased][i]((cgEventArgs){ .touchReleased = { .touchID = event.tfinger.touchId, .fingerID = event.tfinger.fingerId, .x = event.tfinger.x, .y = event.tfinger.y, .dx = event.tfinger.dx, .dy = event.tfinger.dy, .pressure = event.tfinger.pressure } });
				}
				break;
			case SDL_WINDOWEVENT:
				switch (event.window.event)
				{
					case SDL_WINDOWEVENT_ENTER:
						for (int i = 0; i < cgListLength(callbacks[cgEventMouseFocused]); i++)
						{
							callbacks[cgEventMouseFocused][i]((cgEventArgs){ .mouseFocused = { .focused = true } });
						}
						break;
					case SDL_WINDOWEVENT_LEAVE:
						for (int i = 0; i < cgListLength(callbacks[cgEventMouseFocused]); i++)
						{
							callbacks[cgEventMouseFocused][i]((cgEventArgs){ .mouseFocused = { .focused = false } });
						}
						break;
					case SDL_WINDOWEVENT_FOCUS_GAINED:
						for (int i = 0; i < cgListLength(callbacks[cgEventWindowFocused]); i++)
						{
							callbacks[cgEventWindowFocused][i]((cgEventArgs){ .windowFocused = { .focused = true } });
						}
						break;
					case SDL_WINDOWEVENT_FOCUS_LOST:
						for (int i = 0; i < cgListLength(callbacks[cgEventWindowFocused]); i++)
						{
							callbacks[cgEventWindowFocused][i]((cgEventArgs){ .windowFocused = { .focused = false } });
						}
						break;
					case SDL_WINDOWEVENT_RESIZED:
						for (int i = 0; i < cgListLength(callbacks[cgEventWindowResized]); i++)
						{
							callbacks[cgEventWindowResized][i]((cgEventArgs){ .windowResized = { .width = event.window.data1, .height = event.window.data2 } });
						}
						break;
					case SDL_WINDOWEVENT_SHOWN:
						for (int i = 0; i < cgListLength(callbacks[cgEventWindowVisible]); i++)
						{
							callbacks[cgEventWindowVisible][i]((cgEventArgs){ .windowVisible = { .visible = true } });
						}
						break;
					case SDL_WINDOWEVENT_HIDDEN:
						for (int i = 0; i < cgListLength(callbacks[cgEventWindowVisible]); i++)
						{
							callbacks[cgEventWindowVisible][i]((cgEventArgs){ .windowVisible = { .visible = false } });
						}
						break;
					default: break;
				}
				break;
			default: break;
		}
	}
}

void cgEventPush(cgEvent event, cgEventArgs args) // incomplete
{
	SDL_Event sdlEvent = { 0 };
	switch (event)
	{
		case cgEventGamepadAxis:
			break;
		case cgEventGamepadPressed:
			break;
		case cgEventGamepadReleased:
			break;
		case cgEventJoystickAdded:
			break;
		case cgEventJoystickAxis:
			break;
		case cgEventJoystickHat:
			break;
		case cgEventJoystickPressed:
			break;
		case cgEventJoystickReleased:
			break;
		case cgEventJoystickRemoved:
			break;
		case cgEventKeyPressed:
			break;
		case cgEventKeyReleased:
			break;
		case cgEventLowMemory:
			break;
		case cgEventMouseFocused:
			break;
		case cgEventMouseMoved:
			break;
		case cgEventMousePressed:
			break;
		case cgEventMouseReleased:
			break;
		case cgEventMouseWheelMoved:
			break;
		case cgEventOnQuit:
			break;
		case cgEventTextInput:
			break;
		case cgEventTouchMoved:
			break;
		case cgEventTouchPressed:
			break;
		case cgEventTouchReleased:
			break;
		case cgEventWindowFocused:
			break;
		case cgEventWindowResized:
			break;
		case cgEventWindowVisible:
			break;
		default: break;
	}
	SDL_PushEvent(&sdlEvent);
	abort();
}

void cgEventQuit()
{
	cgEventPush(cgEventOnQuit, (cgEventArgs){ 0 });
}

void cgEventRemoveCallback(cgEvent event, cgEventCallback callback)
{
	callbacks[event] = cgListRemoveAll(callbacks[event], callback);
}
