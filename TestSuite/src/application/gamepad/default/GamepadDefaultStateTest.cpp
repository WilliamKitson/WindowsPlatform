#include "GamepadDefaultStateTest.h"

GamepadDefaultStateTest::GamepadDefaultStateTest()
{
}

GamepadDefaultStateTest::~GamepadDefaultStateTest()
{
}

std::string GamepadDefaultStateTest::test()
{
	if (WindowsPlatform::XInputGamepad().getState() == WindowsPlatform::GamepadState())
	{
		return std::string();
	}

	return "gamepad default state test failed\n";
}
