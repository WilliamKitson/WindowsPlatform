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
	failures += testSet();
	failures += testMinimum();

	return failures;
}

std::string WindowResolutionTester::testDefault()
{
	return WindowResolutionDefaultTest(hInstance, nCmdShow).test();
}

std::string WindowResolutionTester::testSet()
{
	return WindowResolutionSetTest(hInstance, nCmdShow).test();
}

std::string WindowResolutionTester::testMinimum()
{
	return WindowResolutionMinimumTest(hInstance, nCmdShow).test();
}
