#include "ApplicationTester.h"

ApplicationTester::ApplicationTester()
{
}

ApplicationTester::~ApplicationTester()
{
}

std::string ApplicationTester::test()
{
	std::string failures{ "" };

	failures += testDelta();
	failures += testGamepad();

	return failures;
}

std::string ApplicationTester::testDelta()
{
	return DeltaTester().test();
}

std::string ApplicationTester::testGamepad()
{
	return GamepadTester().test();
}
