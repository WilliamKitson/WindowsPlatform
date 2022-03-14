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

	failures += testResolution();
	failures += testMouseState();

	return failures;
}

std::string PresentationTester::testResolution()
{
	return ResolutionTester().test();
}

std::string PresentationTester::testMouseState()
{
	return MouseStateTester().test();
}
