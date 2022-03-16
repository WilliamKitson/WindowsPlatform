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

	return failures;
}

std::string ResolutionValidatorTester::testDefault()
{
	return ResolutionValidatorDefaultTester().test();
}
