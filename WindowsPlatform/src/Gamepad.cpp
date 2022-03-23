#include "Gamepad.h"

windowsPlatform::Gamepad::Gamepad()
{
}

windowsPlatform::Gamepad::~Gamepad()
{
}

windowsPlatform::Vector2 windowsPlatform::Gamepad::getJoystickLeft()
{
	return Vector2();
}

windowsPlatform::Vector2 windowsPlatform::Gamepad::getJoystickRight()
{
	return Vector2();
}

float windowsPlatform::Gamepad::getTriggerLeft()
{
	return 0.0f;
}

float windowsPlatform::Gamepad::getTriggerRight()
{
	return 0.0f;
}

bool windowsPlatform::Gamepad::getButton(GamepadButtons)
{
	return false;
}
