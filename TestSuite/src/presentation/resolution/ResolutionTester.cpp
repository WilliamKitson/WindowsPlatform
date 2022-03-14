#include "ResolutionTester.h"

ResolutionTester::ResolutionTester()
{
}

ResolutionTester::~ResolutionTester()
{
}

std::string ResolutionTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testWidth();
	failures += testHeight();

	return failures;
}

std::string ResolutionTester::testDefault()
{
	return ResolutionDefaultTest().test();
}

std::string ResolutionTester::testWidth()
{
	return ResolutionWidthTest().test();
}

std::string ResolutionTester::testHeight()
{
	return ResolutionHeightTest().test();
}
