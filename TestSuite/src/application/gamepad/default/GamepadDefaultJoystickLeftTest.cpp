#include "GamepadDefaultJoystickLeftTest.h"

GamepadDefaultJoystickLeftTest::GamepadDefaultJoystickLeftTest()
{
}

GamepadDefaultJoystickLeftTest::~GamepadDefaultJoystickLeftTest()
{
}

std::string GamepadDefaultJoystickLeftTest::test()
{
	if (windowsPlatform::Gamepad().getJoystickLeft() == windowsPlatform::Vector2())
	{
		return std::string();
	}

	return "gamepad default joystick left test failed\n";
}
