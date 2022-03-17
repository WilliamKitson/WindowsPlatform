#include "ResolutionValidatorTester.h"

ResolutionValidatorTester::ResolutionValidatorTester()
{
}

ResolutionValidatorTester::~ResolutionValidatorTester()
{
}

std::string ResolutionValidatorTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testParameter();
	failures += testMinimum();

	return failures;
}

std::string ResolutionValidatorTester::testDefault()
{
	return ResolutionDefaultTester().test();
}

std::string ResolutionValidatorTester::testParameter()
{
	return ResolutionParameterTester().test();
}

std::string ResolutionValidatorTester::testMinimum()
{
	return ResolutionMinimumTester().test();
}
