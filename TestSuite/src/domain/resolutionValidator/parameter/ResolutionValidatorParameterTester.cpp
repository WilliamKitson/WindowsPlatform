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

	return failures;
}

std::string ResolutionValidatorParameterTester::testWidth()
{
	return ResolutionValidatorParameterWidthTest().test();
}
