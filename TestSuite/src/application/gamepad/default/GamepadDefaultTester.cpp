#include "GamepadDefaultTester.h"

GamepadDefaultTester::GamepadDefaultTester()
{
}

GamepadDefaultTester::~GamepadDefaultTester()
{
}

std::string GamepadDefaultTester::test()
{
	std::string failures{ "" };

	failures += testJoystickLeft();
	failures += testJoystickRight();

	return failures;
}

std::string GamepadDefaultTester::testJoystickLeft()
{
	return GamepadDefaultJoystickLeftTest().test();
}

std::string GamepadDefaultTester::testJoystickRight()
{
	return GamepadDefaultJoystickRightTest().test();
}
