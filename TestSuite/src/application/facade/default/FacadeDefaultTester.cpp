#include "FacadeDefaultTester.h"

FacadeDefaultTester::FacadeDefaultTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeDefaultTester::~FacadeDefaultTester()
{
}

std::string FacadeDefaultTester::test()
{
	std::string failures{ "" };

	failures += testMinimise();
	failures += testCursor();
	failures += testDrag();
	failures += testMouse();
	failures += testKeyboard();

	return failures;
}

std::string FacadeDefaultTester::testMinimise()
{
	return FacadeDefaultMinimiseTest(hInstance, nCmdShow).test();
}

std::string FacadeDefaultTester::testCursor()
{
	return FacadeDefaultCursorTest(hInstance, nCmdShow).test();
}

std::string FacadeDefaultTester::testDrag()
{
	return FacadeDefaultDragTest(hInstance, nCmdShow).test();
}

std::string FacadeDefaultTester::testMouse()
{
	return FacadeDefaultMouseTest(hInstance, nCmdShow).test();
}

std::string FacadeDefaultTester::testKeyboard()
{
	return FacadeDefaultKeyboardTest(hInstance, nCmdShow).test();
}
