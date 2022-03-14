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

	failures += testCursorX();
	failures += testCursorY();
	failures += testDragX();
	failures += testDragY();
	failures += testButtons();
	failures += testQuit();
	failures += testOpenPostQuit();
	failures += testMinimise();

	return failures;
}

std::string WindowEventTester::testCursorX()
{
	return WindowEventCursorXTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testCursorY()
{
	return WindowEventCursorYTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testDragX()
{
	return WindowEventDragXTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testDragY()
{
	return WindowEventDragYTest(hInstance, nCmdShow).test();
}

std::string WindowEventTester::testButtons()
{
	return WindowEventButtonsTest(hInstance, nCmdShow).test();
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
