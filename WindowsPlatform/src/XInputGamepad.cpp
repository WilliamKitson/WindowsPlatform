#include "XInputGamepad.h"

WindowsPlatform::XInputGamepad::XInputGamepad()
{
}

WindowsPlatform::XInputGamepad::~XInputGamepad()
{
}

WindowsPlatform::Vector2 WindowsPlatform::XInputGamepad::getJoystickLeft()
{
	return Vector2();
}

WindowsPlatform::Vector2 WindowsPlatform::XInputGamepad::getJoystickRight()
{
	return Vector2();
}

float WindowsPlatform::XInputGamepad::getTriggerLeft()
{
	return 0.0f;
}

float WindowsPlatform::XInputGamepad::getTriggerRight()
{
	return 0.0f;
}

bool WindowsPlatform::XInputGamepad::getButton(GamepadButtons)
{
	return false;
}
