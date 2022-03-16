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

	return failures;
}

std::string ResolutionValidatorTester::testDefault()
{
	return ResolutionValidatorDefaultTester().test();
}

std::string ResolutionValidatorTester::testParameter()
{
	return ResolutionValidatorParameterTester().test();
}
