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
	failures += testTriggerLeft();

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

std::string GamepadDefaultTester::testTriggerLeft()
{
	return GamepadDefaultTriggerLeftTest().test();
}
