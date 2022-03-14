#include "WindowEventDragYTest.h"

WindowEventDragYTest::WindowEventDragYTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventDragYTest::~WindowEventDragYTest()
{
}

std::string WindowEventDragYTest::test()
{
	ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window event drag y test"
	};

	if (unit.getDragY() == 0)
	{
		return std::string();
	}

	return "windows event drag y test failed\n";
}
