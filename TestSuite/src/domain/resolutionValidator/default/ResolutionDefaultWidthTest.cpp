#include "ResolutionDefaultWidthTest.h"

ResolutionDefaultWidthTest::ResolutionDefaultWidthTest()
{
}

ResolutionDefaultWidthTest::~ResolutionDefaultWidthTest()
{
}

std::string ResolutionDefaultWidthTest::test()
{
	if (WindowsPlatform::ResolutionValidator().getWidth() == 960)
	{
		return std::string();
	}

	return "resolution validator default width test failed\n";
}
