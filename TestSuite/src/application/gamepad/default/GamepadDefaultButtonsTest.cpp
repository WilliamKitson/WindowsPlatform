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
	WindowsPlatform::XInputGamepad unit;

	for (int i{ 0 }; i < (int)WindowsPlatform::GamepadButtons::size; i++)
	{
		successes += unit.getButton((WindowsPlatform::GamepadButtons)i) == false;
	}

	if (successes == (int)WindowsPlatform::GamepadButtons::size)
	{
		return std::string();
	}

	return "gamepad default buttons test failed\n";
}
