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

	failures += testTag();
	failures += testResolution();
	failures += testDestroyed();

	return failures;
}

std::string WindowTester::testTag()
{
	return WindowTagTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testResolution()
{
	return WindowResolutionTester(hInstance, nCmdShow).test();
}

std::string WindowTester::testDestroyed()
{
	return WindowDestroyedTest(hInstance, nCmdShow).test();
}
