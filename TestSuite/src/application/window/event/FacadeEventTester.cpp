#include "FacadeEventTester.h"

FacadeEventTester::FacadeEventTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeEventTester::~FacadeEventTester()
{
}

std::string FacadeEventTester::test()
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

std::string FacadeEventTester::testQuit()
{
	return FacadeEventQuitTest(hInstance, nCmdShow).test();
}

std::string FacadeEventTester::testMinimise()
{
	return FacadeEventMinimiseTest(hInstance, nCmdShow).test();
}

std::string FacadeEventTester::testCursor()
{
	return FacadeEventCursorTest(hInstance, nCmdShow).test();
}

std::string FacadeEventTester::testDrag()
{
	return FacadeEventDragTest(hInstance, nCmdShow).test();
}

std::string FacadeEventTester::testMouse()
{
	return FacadeEventMouseTest(hInstance, nCmdShow).test();
}

std::string FacadeEventTester::testKeyboard()
{
	return FacadeEventKeyboardTest(hInstance, nCmdShow).test();
}
