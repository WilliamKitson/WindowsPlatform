#include "FacadeWindowTester.h"

FacadeWindowTester::FacadeWindowTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeWindowTester::~FacadeWindowTester()
{
}

std::string FacadeWindowTester::test()
{
	std::string failures{ "" };

	failures += testTag();
	failures += testResolution();

	return failures;
}

std::string FacadeWindowTester::testTag()
{
	return FacadeWindowTagTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testResolution()
{
	return FacadeWindowResolutionTest(hInstance, nCmdShow).test();
}
