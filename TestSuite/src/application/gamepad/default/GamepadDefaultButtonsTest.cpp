#include "GamepadDefaultButtonsTest.h"

GamepadDefaultButtonsTest::GamepadDefaultButtonsTest()
	: successes{ 0 }
{
}

GamepadDefaultButtonsTest::~GamepadDefaultButtonsTest()
{
}

std::string GamepadDefaultButtonsTest::test()
{
	for (int i{ 0 }; i < (int)WindowsPlatform::GamepadButtons::gamepadButtonsSize; i++)
	{
		successes += WindowsPlatform::XInputGamepad().getButton((WindowsPlatform::GamepadButtons)i) == false;
	}

	if (successes == (int)WindowsPlatform::GamepadButtons::gamepadButtonsSize)
	{
		return std::string();
	}

	return "gamepad default buttons test failed\n";
}
