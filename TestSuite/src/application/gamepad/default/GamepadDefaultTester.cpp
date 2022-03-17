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

	return failures;
}

std::string GamepadDefaultTester::testJoystickLeft()
{
	return GamepadDefaultJoystickLeftTest().test();
}
