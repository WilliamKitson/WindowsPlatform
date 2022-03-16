#include "ResolutionValidatorMinimumWidthTest.h"

ResolutionValidatorMinimumWidthTest::ResolutionValidatorMinimumWidthTest()
{
}

ResolutionValidatorMinimumWidthTest::~ResolutionValidatorMinimumWidthTest()
{
}

std::string ResolutionValidatorMinimumWidthTest::test()
{
	WindowsPlatform::ResolutionValidator unit;

	unit.setResolution(0, 0);

	if (unit.getWidth() == 960)
	{
		return std::string();
	}

	return "resolution validator minimum width test failed\n";
}
