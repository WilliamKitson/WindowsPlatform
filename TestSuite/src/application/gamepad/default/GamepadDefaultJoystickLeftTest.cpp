#include "GamepadDefaultJoystickLeftTest.h"

GamepadDefaultJoystickLeftTest::GamepadDefaultJoystickLeftTest()
{
}

GamepadDefaultJoystickLeftTest::~GamepadDefaultJoystickLeftTest()
{
}

std::string GamepadDefaultJoystickLeftTest::test()
{
	if (WindowsPlatform::Gamepad().getJoystickLeft() == WindowsPlatform::Vector2())
	{
		return std::string();
	}

	return "gamepad default joystick left test failed\n";
}
