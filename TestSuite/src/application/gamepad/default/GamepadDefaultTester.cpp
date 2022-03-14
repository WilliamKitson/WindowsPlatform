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

	return failures;
}

std::string GamepadDefaultTester::testState()
{
	return GamepadDefaultStateTest().test();
}
