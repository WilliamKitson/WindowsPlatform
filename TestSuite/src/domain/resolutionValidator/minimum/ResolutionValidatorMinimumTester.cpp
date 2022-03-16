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

	return failures;
}

std::string ResolutionValidatorMinimumTester::testWidth()
{
	return ResolutionValidatorMinimumWidthTest().test();
}
