#include "WindowTester.h"

WindowTester::WindowTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowTester::~WindowTester()
{
}

std::string WindowTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testTag();
	failures += testResolution();
	failures += testStyle();
	failures += testEvent();
	failures += testDestroyed();
	failures += testOpenPostQuit();

	return failures;
}

std::string WindowTester::testDefault()
{
	return FacadeDefaultTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testTag()
{
	return FacadeTagTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testResolution()
{
	return FacadeResolutionTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testStyle()
{
	return FacadeStyleTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testEvent()
{
	return FacadeEventTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testDestroyed()
{
	return FacadeDestroyedTest(hInstance, nCmdShow).test();
}

std::string WindowTester::testOpenPostQuit()
{
	return WindowOpenPostQuitTest(hInstance, nCmdShow).test();
}
