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

	failures += testDestroyed();
	failures += testDefault();
	failures += testTag();
	failures += testResolution();
	failures += testStyle();
	failures += testEvent();

	return failures;
}

std::string WindowTester::testDestroyed()
{
	return WindowDestoroyedTest(hInstance, nCmdShow).test();
}

std::string WindowTester::testDefault()
{
	return WindowDefaultTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testTag()
{
	return WindowTagTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testResolution()
{
	return WindowResolutionTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testStyle()
{
	return WindowStyleTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testEvent()
{
	return WindowEventTester(hInstance, nCmdShow).test();
}
