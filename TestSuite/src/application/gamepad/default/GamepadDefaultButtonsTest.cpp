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
	windowsPlatform::Gamepad unit;

	for (int i{ 0 }; i < (int)windowsPlatform::GamepadButtons::size; i++)
	{
		successes += unit.getButton((windowsPlatform::GamepadButtons)i) == false;
	}

	if (successes == (int)windowsPlatform::GamepadButtons::size)
	{
		return std::string();
	}

	return "gamepad default buttons test failed\n";
}
