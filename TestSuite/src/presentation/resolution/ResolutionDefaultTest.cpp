#include "ResolutionDefaultTest.h"

ResolutionDefaultTest::ResolutionDefaultTest()
{
}

ResolutionDefaultTest::~ResolutionDefaultTest()
{
}

std::string ResolutionDefaultTest::test()
{
	WindowsPlatform::Resolution unit{
		0,
		0
	};

	if (unit == WindowsPlatform::Resolution())
	{
		return std::string();
	}

	return "resolution default test failed\n";
}
