#include "ResolutionDefaultTester.h"

ResolutionDefaultTester::ResolutionDefaultTester()
{
}

ResolutionDefaultTester::~ResolutionDefaultTester()
{
}

std::string ResolutionDefaultTester::test()
{
	std::string failures{ "" };

	failures += testWidth();

	return failures;
}

std::string ResolutionDefaultTester::testWidth()
{
	return ResolutionDefaultWidthTest().test();
}
