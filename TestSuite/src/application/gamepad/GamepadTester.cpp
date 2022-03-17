#include "GamepadTester.h"

GamepadTester::GamepadTester()
{
}

GamepadTester::~GamepadTester()
{
}

std::string GamepadTester::test()
{
	std::string failures{ "" };

	failures += testDefault();

	return failures;
}

std::string GamepadTester::testDefault()
{
	return GamepadDefaultTester().test();
}
