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

	return failures;
}

std::string ApplicationTester::testDelta()
{
	return DeltaTester().test();
}
