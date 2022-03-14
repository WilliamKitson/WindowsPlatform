#include "WindowEventOpenPostQuit.h"

WindowEventOpenPostQuitTest::WindowEventOpenPostQuitTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventOpenPostQuitTest::~WindowEventOpenPostQuitTest()
{
}

std::string WindowEventOpenPostQuitTest::test()
{
	ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window open post quit test: QUIT TO CONTINUE"
	};

	while (unit.getQuit() == false)
	{
		unit.update();
	}

	if (IsWindow(unit.getWindow()))
	{
		return std::string();
	}

	return "window event open post quit test failed\n";
}
