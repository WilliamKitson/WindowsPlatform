#include "WindowEventTester.h"

WindowEventTester::WindowEventTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventTester::~WindowEventTester()
{
}

std::string WindowEventTester::test()
{
	std::string failures{ "" };

	failures += testQuit();
	failures += testOpenPostQuit();
	failures += testMinimise();
	failures += testKeys();

	return failures;
}

std::string WindowEventTester::testQuit()
{
	return WindowEventQuitTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testOpenPostQuit()
{
	return WindowEventOpenPostQuitTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testMinimise()
{
	return WindowEventMinimiseTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testKeys()
{
	return WindowEventKeysTest(hInstance, nCmdShow).test();
}
