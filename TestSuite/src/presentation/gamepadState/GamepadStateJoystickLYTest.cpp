#include "GamepadStateJoystickLYTest.h"

GamepadStateJoystickLYTest::GamepadStateJoystickLYTest()
{
}

GamepadStateJoystickLYTest::~GamepadStateJoystickLYTest()
{
}

std::string GamepadStateJoystickLYTest::test()
{
	WindowsPlatform::GamepadState unit{
		0.0f,
		1.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f
	};

	if ((unit == WindowsPlatform::GamepadState()) == false)
	{
		return std::string();
	}

	return "gamepad state joystick LY test failed\n";
}
