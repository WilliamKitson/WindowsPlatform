#include "ResolutionValidatorParameterTester.h"

ResolutionValidatorParameterTester::ResolutionValidatorParameterTester()
{
}

ResolutionValidatorParameterTester::~ResolutionValidatorParameterTester()
{
}

std::string ResolutionValidatorParameterTester::test()
{
	std::string failures{ "" };

	failures += testWidth();
	failures += testHeight();

	return failures;
}

std::string ResolutionValidatorParameterTester::testWidth()
{
	return ResolutionParameterWidthTest().test();
}

std::string ResolutionValidatorParameterTester::testHeight()
{
	return ResolutionParameterHeightTest().test();
}
