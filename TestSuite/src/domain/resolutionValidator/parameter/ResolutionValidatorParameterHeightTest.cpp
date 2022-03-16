#include "ResolutionValidatorParameterHeightTest.h"

ResolutionValidatorParameterHeightTest::ResolutionValidatorParameterHeightTest()
	: height{ 1000 }
{
}

ResolutionValidatorParameterHeightTest::~ResolutionValidatorParameterHeightTest()
{
}

std::string ResolutionValidatorParameterHeightTest::test()
{
	WindowsPlatform::ResolutionValidator unit;

	unit.setResolution(0, height);

	if (unit.getHeight() == height)
	{
		return std::string();
	}

	return "resolution validator parameter height test failed\n";
}
