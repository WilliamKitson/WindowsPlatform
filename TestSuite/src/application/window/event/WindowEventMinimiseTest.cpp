#include "WindowEventMinimiseTest.h"

WindowEventMinimiseTest::WindowEventMinimiseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventMinimiseTest::~WindowEventMinimiseTest()
{
}

std::string WindowEventMinimiseTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window event minimise test"
	};

	PostMessage(
		unit.getWindow(),
		WM_SIZE,
		SIZE_MINIMIZED,
		0
	);

	unit.update();

	if (unit.getMinimise() == true)
	{
		return std::string();
	}

	return "window event minimise test failed\n";
}
