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

	failures += testState();
	failures += testButtons();

	return failures;
}

std::string GamepadDefaultTester::testState()
{
	return GamepadDefaultStateTest().test();
}

std::string GamepadDefaultTester::testButtons()
{
	return GamepadDefaultButtonsTest().test();
}
