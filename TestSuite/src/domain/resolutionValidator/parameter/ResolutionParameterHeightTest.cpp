#include "ResolutionParameterHeightTest.h"

ResolutionParameterHeightTest::ResolutionParameterHeightTest()
	: height{ 1000 }
{
}

ResolutionParameterHeightTest::~ResolutionParameterHeightTest()
{
}

std::string ResolutionParameterHeightTest::test()
{
	WindowsPlatform::ResolutionValidator unit;

	unit.setResolution(0, height);

	if (unit.getHeight() == height)
	{
		return std::string();
	}

	return "resolution parameter height test failed\n";
}
