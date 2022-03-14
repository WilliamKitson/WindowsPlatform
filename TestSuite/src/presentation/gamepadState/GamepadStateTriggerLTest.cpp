#include "GamepadStateTriggerLTest.h"

GamepadStateTriggerLTest::GamepadStateTriggerLTest()
{
}

GamepadStateTriggerLTest::~GamepadStateTriggerLTest()
{
}

std::string GamepadStateTriggerLTest::test()
{
	WindowsPlatform::GamepadState unit{
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		1.0f,
		0.0f
	};

	if ((unit == WindowsPlatform::GamepadState()) == false)
	{
		return std::string();
	}

	return "gamepad state triggerL test failed\n";
}
