#include "ResolutionValidatorDefaultTester.h"

ResolutionValidatorDefaultTester::ResolutionValidatorDefaultTester()
{
}

ResolutionValidatorDefaultTester::~ResolutionValidatorDefaultTester()
{
}

std::string ResolutionValidatorDefaultTester::test()
{
	std::string failures{ "" };

	failures += testWidth();

	return failures;
}

std::string ResolutionValidatorDefaultTester::testWidth()
{
	return ResolutionValidatorDefaultWidthTest().test();
}
