#include "GamepadStateJoystickRXTest.h"

GamepadStateJoystickRXTest::GamepadStateJoystickRXTest()
{
}

GamepadStateJoystickRXTest::~GamepadStateJoystickRXTest()
{
}

std::string GamepadStateJoystickRXTest::test()
{
	WindowsPlatform::GamepadState unit{
		0.0f,
		0.0f,
		1.0f,
		0.0f,
		0.0f,
		0.0f
	};

	if ((unit == WindowsPlatform::GamepadState()) == false)
	{
		return std::string();
	}

	return "gamepad state joystick RX test failed\n";
}
