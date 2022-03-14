#include "PresentationTester.h"

PresentationTester::PresentationTester()
{
}

PresentationTester::~PresentationTester()
{
}

std::string PresentationTester::test()
{
	std::string failures{ "" };

	failures += testMouseState();

	return failures;
}

std::string PresentationTester::testMouseState()
{
	return MouseStateTester().test();
}
