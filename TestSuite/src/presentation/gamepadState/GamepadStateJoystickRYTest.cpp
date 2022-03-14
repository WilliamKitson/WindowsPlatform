#include "GamepadStateJoystickRYTest.h"

GamepadStateJoystickRYTest::GamepadStateJoystickRYTest()
{
}

GamepadStateJoystickRYTest::~GamepadStateJoystickRYTest()
{
}

std::string GamepadStateJoystickRYTest::test()
{
	WindowsPlatform::GamepadState unit{
		0.0f,
		0.0f,
		0.0f,
		1.0f,
		0.0f,
		0.0f
	};

	if ((unit == WindowsPlatform::GamepadState()) == false)
	{
		return std::string();
	}

	return "gamepad state joystick RY test failed\n";
}
