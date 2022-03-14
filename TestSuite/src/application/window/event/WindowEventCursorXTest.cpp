#include "WindowEventCursorXTest.h"

WindowEventCursorXTest::WindowEventCursorXTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventCursorXTest::~WindowEventCursorXTest()
{
}

std::string WindowEventCursorXTest::test()
{
	if (WindowsPlatform::ApplicationWindow(hInstance, nCmdShow, "window event x test").getCursorX() == unsigned int(0))
	{
		return std::string();
	}

	return "window event x test failed\n";
}
