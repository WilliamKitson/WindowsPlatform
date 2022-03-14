#include "XInputGamepad.h"

WindowsPlatform::XInputGamepad::XInputGamepad()
{
}

WindowsPlatform::XInputGamepad::~XInputGamepad()
{
}

WindowsPlatform::GamepadState WindowsPlatform::XInputGamepad::getState()
{
	return GamepadState();
}

bool WindowsPlatform::XInputGamepad::getButton(GamepadButtons)
{
	return false;
}
