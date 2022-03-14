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
	failures += testJoystickLY();
	failures += testJoystickRX();

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

std::string GamepadStateTester::testJoystickLY()
{
	return GamepadStateJoystickLYTest().test();
}

std::string GamepadStateTester::testJoystickRX()
{
	return GamepadStateJoystickRXTest().test();
}
