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
	failures += testHeight();

	return failures;
}

std::string ResolutionValidatorDefaultTester::testWidth()
{
	return ResolutionDefaultWidthTest().test();
}

std::string ResolutionValidatorDefaultTester::testHeight()
{
	return ResolutionValidatorDefaultHeightTest().test();
}
