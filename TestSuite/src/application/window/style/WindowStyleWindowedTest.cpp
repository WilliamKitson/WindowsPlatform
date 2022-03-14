#include "WindowStyleWindowedTest.h"

WindowStyleWindowedTest::WindowStyleWindowedTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowStyleWindowedTest::~WindowStyleWindowedTest()
{
}

std::string WindowStyleWindowedTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window style windowed test"
	};

	unit.setBorderless();
	unit.setWindowed();

	DWORD style = (DWORD)GetWindowLongPtr(unit.getWindow(), GWL_STYLE);
	DWORD windowed{ WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION };

	if ((style & windowed) == windowed)
	{
		return std::string();
	}

	return "window style windowed test failed\n";
}
