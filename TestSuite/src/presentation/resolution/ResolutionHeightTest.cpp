#include "ResolutionHeightTest.h"

ResolutionHeightTest::ResolutionHeightTest()
{
}

ResolutionHeightTest::~ResolutionHeightTest()
{
}

std::string ResolutionHeightTest::test()
{
	WindowsPlatform::Resolution unit{
		0,
		1
	};

	if ((unit == WindowsPlatform::Resolution()) == false)
	{
		return std::string();
	}

	return "resolution height test failed\n";
}
