#include "WindowsStyleBorderlessTest.h"

WindowsStyleBorderlessTest::WindowsStyleBorderlessTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowsStyleBorderlessTest::~WindowsStyleBorderlessTest()
{
}

std::string WindowsStyleBorderlessTest::test()
{
	WindowsPlatform::SubordinateImplimentation unit{
		hInstance,
		nCmdShow,
		"window style borderless test"
	};

	unit.setBorderless();

	DWORD style = (DWORD)GetWindowLongPtr(unit.getWindow(), GWL_STYLE);

	if ((style & WS_POPUPWINDOW) == WS_POPUPWINDOW)
	{
		return std::string();
	}

	return "windows style borderless test failed\n";
}
