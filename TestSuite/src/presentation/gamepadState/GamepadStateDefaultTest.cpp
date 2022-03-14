#include "GamepadStateDefaultTest.h"

GamepadStateDefaultTest::GamepadStateDefaultTest()
{
}

GamepadStateDefaultTest::~GamepadStateDefaultTest()
{
}

std::string GamepadStateDefaultTest::test()
{
	WindowsPlatform::GamepadState unit{
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f
	};

	if (unit == WindowsPlatform::GamepadState())
	{
		return std::string();
	}

	return "gamepad state default test failed\n";
}
