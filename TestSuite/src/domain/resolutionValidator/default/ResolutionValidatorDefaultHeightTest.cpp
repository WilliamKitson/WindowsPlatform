#include "ResolutionValidatorDefaultHeightTest.h"

ResolutionValidatorDefaultHeightTest::ResolutionValidatorDefaultHeightTest()
{
}

ResolutionValidatorDefaultHeightTest::~ResolutionValidatorDefaultHeightTest()
{
}

std::string ResolutionValidatorDefaultHeightTest::test()
{
	if (WindowsPlatform::ResolutionValidator().getHeight() == 540)
	{
		return std::string();
	}

	return "resolution validator default height test failed\n";
}
