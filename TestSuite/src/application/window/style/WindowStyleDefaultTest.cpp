#include "WindowStyleDefaultTest.h"

WindowStyleDefaultTest::WindowStyleDefaultTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowStyleDefaultTest::~WindowStyleDefaultTest()
{
}

std::string WindowStyleDefaultTest::test()
{
	ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window style default test"
	};

	DWORD style = (DWORD)GetWindowLongPtr(unit.getWindow(), GWL_STYLE);
	DWORD windowed{ WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION };

	if ((style & windowed) == windowed)
	{
		return std::string();
	}

	return "window style default test failed\n";
}
