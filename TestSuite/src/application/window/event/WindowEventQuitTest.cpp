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

	PostMessage(
		unit.getWindow(),
		WM_CLOSE,
		0,
		0
	);

	unit.update();

	if (unit.getQuit() == true)
	{
		return std::string();
	}

	return "window event quit test failed\n";
}
