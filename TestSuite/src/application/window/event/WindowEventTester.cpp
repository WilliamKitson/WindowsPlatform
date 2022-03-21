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
	failures += testMinimise();
	failures += testCursor();
	failures += testDrag();
	failures += testMouse();
	failures += testKeyboard();

	return failures;
}

std::string WindowEventTester::testQuit()
{
	return FacadeEventQuitTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testMinimise()
{
	return FacadeEventMinimiseTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testCursor()
{
	return WindowEventCursorTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testDrag()
{
	return WindowEventDragTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testMouse()
{
	return WindowEventMouseTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testKeyboard()
{
	return WindowEventKeyboardTest(hInstance, nCmdShow).test();
}
