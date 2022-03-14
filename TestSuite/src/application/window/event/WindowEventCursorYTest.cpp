#include "WindowEventCursorYTest.h"

WindowEventCursorYTest::WindowEventCursorYTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventCursorYTest::~WindowEventCursorYTest()
{
}

std::string WindowEventCursorYTest::test()
{
	if (ApplicationWindow(hInstance, nCmdShow, "window event y test").getCursorY() == unsigned int(0))
	{
		return std::string();
	}

	return "window event y test failed\n";
}
