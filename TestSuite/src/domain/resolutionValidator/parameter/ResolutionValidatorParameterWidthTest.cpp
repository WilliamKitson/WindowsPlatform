#include "ResolutionValidatorParameterWidthTest.h"

ResolutionValidatorParameterWidthTest::ResolutionValidatorParameterWidthTest()
	: width{ 1000 }
{
}

ResolutionValidatorParameterWidthTest::~ResolutionValidatorParameterWidthTest()
{
}

std::string ResolutionValidatorParameterWidthTest::test()
{
	WindowsPlatform::ResolutionValidator unit;

	unit.setResolution(width, 0);

	if (unit.getWidth() == width)
	{
		return std::string();
	}

	return "resolution validator parameter width test failed\n";
}
