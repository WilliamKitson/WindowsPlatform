#include "ResolutionDefaultHeightTest.h"

ResolutionDefaultHeightTest::ResolutionDefaultHeightTest()
{
}

ResolutionDefaultHeightTest::~ResolutionDefaultHeightTest()
{
}

std::string ResolutionDefaultHeightTest::test()
{
	if (windowsPlatform::ResolutionValidator().getHeight() == 540)
	{
		return std::string();
	}

	return "resolution default height test failed\n";
}
