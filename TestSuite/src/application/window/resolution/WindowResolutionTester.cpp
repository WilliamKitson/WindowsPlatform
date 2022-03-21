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

	failures += testDefaultWidth();
	failures += testDefaultHeight();
	failures += testSetWidth();
	failures += testSetHeight();
	failures += testMinimumWidth();
	failures += testMinimumHeight();

	return failures;
}

std::string WindowResolutionTester::testDefaultWidth()
{
	return FacadeResolutionDefaultWidthTest(hInstance, nCmdShow).test();
}

std::string WindowResolutionTester::testDefaultHeight()
{
	return WindowResolutionDefaultHeightTest(hInstance, nCmdShow).test();
}

std::string WindowResolutionTester::testSetWidth()
{
	return WindowsResolutionSetWidthTest(hInstance, nCmdShow).test();
}

std::string WindowResolutionTester::testSetHeight()
{
	return WindowResolutionSetHeightTest(hInstance, nCmdShow).test();
}

std::string WindowResolutionTester::testMinimumWidth()
{
	return WindowResolutionMinimumWidthTest(hInstance, nCmdShow).test();
}

std::string WindowResolutionTester::testMinimumHeight()
{
	return WindowResolutionMinimumHeightTest(hInstance, nCmdShow).test();
}
