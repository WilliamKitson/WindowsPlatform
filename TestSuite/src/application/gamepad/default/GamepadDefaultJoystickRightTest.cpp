#include "GamepadDefaultJoystickRightTest.h"

GamepadDefaultJoystickRightTest::GamepadDefaultJoystickRightTest()
{
}

GamepadDefaultJoystickRightTest::~GamepadDefaultJoystickRightTest()
{
}

std::string GamepadDefaultJoystickRightTest::test()
{
	if (WindowsPlatform::Gamepad().getJoystickRight() == WindowsPlatform::Vector2())
	{
		return std::string();
	}

	return "gamepad defualt joystick right test failed\n";
}
