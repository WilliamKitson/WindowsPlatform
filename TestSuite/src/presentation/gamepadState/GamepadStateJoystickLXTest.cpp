#include "GamepadStateJoystickLXTest.h"

GamepadStateJoystickLXTest::GamepadStateJoystickLXTest()
{
}

GamepadStateJoystickLXTest::~GamepadStateJoystickLXTest()
{
}

std::string GamepadStateJoystickLXTest::test()
{
	WindowsPlatform::GamepadState unit{
		1.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f
	};

	if ((unit == WindowsPlatform::GamepadState()) == false)
	{
		return std::string();
	}

	return "gamepad state joystick LX test failed\n";
}
