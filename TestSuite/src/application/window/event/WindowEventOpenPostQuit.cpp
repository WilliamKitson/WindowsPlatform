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
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window open post quit test"
	};

	PostMessage(
		unit.getWindow(),
		WM_CLOSE,
		0,
		0
	);

	unit.update();

	if (IsWindow(unit.getWindow()))
	{
		return std::string();
	}

	return "window event open post quit test failed\n";
}
