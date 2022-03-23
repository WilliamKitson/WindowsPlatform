#include "GamepadDefaultJoystickRightTest.h"

GamepadDefaultJoystickRightTest::GamepadDefaultJoystickRightTest()
{
}

GamepadDefaultJoystickRightTest::~GamepadDefaultJoystickRightTest()
{
}

std::string GamepadDefaultJoystickRightTest::test()
{
	if (windowsPlatform::Gamepad().getJoystickRight() == windowsPlatform::Vector2())
	{
		return std::string();
	}

	return "gamepad defualt joystick right test failed\n";
}
