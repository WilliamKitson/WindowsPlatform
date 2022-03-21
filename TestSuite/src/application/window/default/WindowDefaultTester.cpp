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
	failures += testCursor();
	failures += testDrag();
	failures += testMouse();
	failures += testKeyboard();

	return failures;
}

std::string WindowDefaultTester::testQuit()
{
	return FacadeDefaultQuitTest(hInstance, nCmdShow).test();
}

std::string WindowDefaultTester::testMinimise()
{
	return FacadeDefaultMinimiseTest(hInstance, nCmdShow).test();
}

std::string WindowDefaultTester::testCursor()
{
	return FacadeDefaultCursorTest(hInstance, nCmdShow).test();
}

std::string WindowDefaultTester::testDrag()
{
	return FacadeDefaultDragTest(hInstance, nCmdShow).test();
}

std::string WindowDefaultTester::testMouse()
{
	return FacadeDefaultMouseTest(hInstance, nCmdShow).test();
}

std::string WindowDefaultTester::testKeyboard()
{
	return WindowDefaultKeyboardTest(hInstance, nCmdShow).test();
}
