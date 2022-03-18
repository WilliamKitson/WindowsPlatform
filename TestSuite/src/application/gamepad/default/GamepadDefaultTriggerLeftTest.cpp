#include "GamepadDefaultTriggerLeftTest.h"

GamepadDefaultTriggerLeftTest::GamepadDefaultTriggerLeftTest()
{
}

GamepadDefaultTriggerLeftTest::~GamepadDefaultTriggerLeftTest()
{
}

std::string GamepadDefaultTriggerLeftTest::test()
{
	if (WindowsPlatform::Gamepad().getTriggerLeft() == 0.0f)
	{
		return std::string();
	}

	return "gamepad default trigger left test failed\n";
}
