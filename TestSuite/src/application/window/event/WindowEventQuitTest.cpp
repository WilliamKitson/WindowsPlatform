#include "WindowEventQuitTest.h"

WindowEventQuitTest::WindowEventQuitTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventQuitTest::~WindowEventQuitTest()
{
}

std::string WindowEventQuitTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window event quit test: QUIT TO CONTINUE"
	};

	while (unit.getQuit() == false)
	{
		unit.update();
	}

	unit.update();

	if (unit.getQuit() == false)
	{
		return std::string();
	}

	return "window event quit test failed\n";
}
