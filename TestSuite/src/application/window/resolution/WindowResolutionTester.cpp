#include "WindowResolutionTester.h"

WindowResolutionTester::WindowResolutionTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowResolutionTester::~WindowResolutionTester()
{
}

std::string WindowResolutionTester::test()
{
	std::string failures{ "" };

	failures += testDefault();

	return failures;
}

std::string WindowResolutionTester::testDefault()
{
	return WindowResolutionDefaultTest(hInstance, nCmdShow).test();
}
