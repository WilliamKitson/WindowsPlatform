#include "Gamepad.h"

WindowsPlatform::Gamepad::Gamepad()
{
}

WindowsPlatform::Gamepad::~Gamepad()
{
}

WindowsPlatform::Vector2 WindowsPlatform::Gamepad::getJoystickLeft()
{
	return Vector2();
}

WindowsPlatform::Vector2 WindowsPlatform::Gamepad::getJoystickRight()
{
	return Vector2();
}

float WindowsPlatform::Gamepad::getTriggerLeft()
{
	return 0.0f;
}

float WindowsPlatform::Gamepad::getTriggerRight()
{
	return 0.0f;
}

bool WindowsPlatform::Gamepad::getButton(GamepadButtons)
{
	return false;
}
