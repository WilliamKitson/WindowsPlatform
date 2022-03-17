#include "GamepadDefaultTriggerRightTest.h"

GamepadDefaultTriggerRightTest::GamepadDefaultTriggerRightTest()
{
}

GamepadDefaultTriggerRightTest::~GamepadDefaultTriggerRightTest()
{
}

std::string GamepadDefaultTriggerRightTest::test()
{
	if (WindowsPlatform::XInputGamepad().getTriggerRight() == 0.0f)
	{
		return std::string();
	}

	return "gamepad default trigger right test failed\n";
}
