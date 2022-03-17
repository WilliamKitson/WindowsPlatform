#include "ResolutionParameterWidthTest.h"

ResolutionParameterWidthTest::ResolutionParameterWidthTest()
	: width{ 1000 }
{
}

ResolutionParameterWidthTest::~ResolutionParameterWidthTest()
{
}

std::string ResolutionParameterWidthTest::test()
{
	WindowsPlatform::ResolutionValidator unit;

	unit.setResolution(width, 0);

	if (unit.getWidth() == width)
	{
		return std::string();
	}

	return "resolution validator parameter width test failed\n";
}
