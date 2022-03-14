#include "ResolutionWidthTest.h"

ResolutionWidthTest::ResolutionWidthTest()
{
}

ResolutionWidthTest::~ResolutionWidthTest()
{
}

std::string ResolutionWidthTest::test()
{
	WindowsPlatform::Resolution unit{
		1,
		0
	};

	if ((unit == WindowsPlatform::Resolution()) == false)
	{
		return std::string();
	}

	return "resolution width test failed\n";
}
