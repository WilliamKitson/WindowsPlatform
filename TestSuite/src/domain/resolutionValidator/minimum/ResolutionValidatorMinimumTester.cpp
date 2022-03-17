#include "ResolutionValidatorMinimumTester.h"

ResolutionValidatorMinimumTester::ResolutionValidatorMinimumTester()
{
}

ResolutionValidatorMinimumTester::~ResolutionValidatorMinimumTester()
{
}

std::string ResolutionValidatorMinimumTester::test()
{
	std::string failures{ "" };

	failures += testWidth();
	failures += testHeight();

	return failures;
}

std::string ResolutionValidatorMinimumTester::testWidth()
{
	return ResolutionMinimumWidthTest().test();
}

std::string ResolutionValidatorMinimumTester::testHeight()
{
	return ResolutionMinimumHeightTest().test();
}
