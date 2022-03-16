#include "ResolutionValidatorMinimumHeightTest.h"

ResolutionValidatorMinimumHeightTest::ResolutionValidatorMinimumHeightTest()
{
}

ResolutionValidatorMinimumHeightTest::~ResolutionValidatorMinimumHeightTest()
{
}

std::string ResolutionValidatorMinimumHeightTest::test()
{
	WindowsPlatform::ResolutionValidator unit;

	unit.setResolution(0, 0);

	if (unit.getHeight() == 540)
	{
		return std::string();
	}

	return "resolution validator minimum height test failed\n";
}
