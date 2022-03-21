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
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade style default test"
	);

	DWORD style = (DWORD)GetWindowLongPtr(
		unit->getWindow(), 
		GWL_STYLE
	);

	delete unit;
	unit = nullptr;

	DWORD windowed{ WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION };

	if ((style & windowed) == windowed)
	{
		return std::string();
	}

	return "facade style default test failed\n";
}
