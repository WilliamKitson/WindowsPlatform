#include "GamepadStateTriggerRTest.h"

GamepadStateTriggerRTest::GamepadStateTriggerRTest()
{
}

GamepadStateTriggerRTest::~GamepadStateTriggerRTest()
{
}

std::string GamepadStateTriggerRTest::test()
{
	WindowsPlatform::GamepadState unit{
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		1.0f
	};

	if ((unit == WindowsPlatform::GamepadState()) == false)
	{
		return std::string();
	}

	return "gamepad state triggerR test failed\n";
}
