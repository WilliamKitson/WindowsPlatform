#include "GamepadStateTester.h"

GamepadStateTester::GamepadStateTester()
{
}

GamepadStateTester::~GamepadStateTester()
{
}

std::string GamepadStateTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testJoystickLX();

	return failures;
}

std::string GamepadStateTester::testDefault()
{
	return GamepadStateDefaultTest().test();
}

std::string GamepadStateTester::testJoystickLX()
{
	return GamepadStateJoystickLXTest().test();
}
