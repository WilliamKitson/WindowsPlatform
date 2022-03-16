#include "ResolutionValidatorDefaultWidthTest.h"

ResolutionValidatorDefaultWidthTest::ResolutionValidatorDefaultWidthTest()
{
}

ResolutionValidatorDefaultWidthTest::~ResolutionValidatorDefaultWidthTest()
{
}

std::string ResolutionValidatorDefaultWidthTest::test()
{
	if (WindowsPlatform::ResolutionValidator().getWidth() == 960)
	{
		return std::string();
	}

	return "resolution validator default width test failed\n";
}
