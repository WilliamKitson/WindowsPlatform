#include "WindowEventDragXTest.h"

WindowEventDragXTest::WindowEventDragXTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventDragXTest::~WindowEventDragXTest()
{
}

std::string WindowEventDragXTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window event drag x test"
	};

	if (unit.getDragX() == 0)
	{
		return std::string();
	}

	return "windows event drag x test failed\n";
}
