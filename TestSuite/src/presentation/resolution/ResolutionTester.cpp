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

	return failures;
}

std::string ResolutionTester::testDefault()
{
	return ResolutionDefaultTester().test();
}
