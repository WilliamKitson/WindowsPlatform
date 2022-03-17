#include "WindowDefaultTester.h"

WindowDefaultTester::WindowDefaultTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowDefaultTester::~WindowDefaultTester()
{
}

std::string WindowDefaultTester::test()
{
	std::string failures{ "" };

	failures += testQuit();
	failures += testMinimise();
	failures += testMouse();
	failures += testCursor();
	failures += testButtons();

	return failures;
}

std::string WindowDefaultTester::testQuit()
{
	return WindowDefaultQuitTest(hInstance, nCmdShow).test();
}

std::string WindowDefaultTester::testMinimise()
{
	return WindowDefaultMinimiseTest(hInstance, nCmdShow).test();
}

std::string WindowDefaultTester::testMouse()
{
	return WindowDefaultMouseTest(hInstance, nCmdShow).test();
}

std::string WindowDefaultTester::testCursor()
{
	return WindowDefaultCursorTest(hInstance, nCmdShow).test();
}

std::string WindowDefaultTester::testButtons()
{
	return WindowDefaultButtonsTest(hInstance, nCmdShow).test();
}
