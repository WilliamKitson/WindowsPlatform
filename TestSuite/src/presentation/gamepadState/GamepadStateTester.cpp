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

	return failures;
}

std::string GamepadStateTester::testDefault()
{
	return GamepadStateDefaultTest().test();
}
