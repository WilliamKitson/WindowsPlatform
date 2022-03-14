#include "WindowStyleBorderlessResolutionTest.h"

WindowStyleBorderlessResolutionTest::WindowStyleBorderlessResolutionTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowStyleBorderlessResolutionTest::~WindowStyleBorderlessResolutionTest()
{
}

std::string WindowStyleBorderlessResolutionTest::test()
{
	ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window style borderless resolution test"
	};

	unit.setBorderless();
	unit.setResolution(1000, 1000);

	RECT resolution;

	GetClientRect(
		unit.getWindow(),
		&resolution
	);

	if ((resolution.right - resolution.left) + (resolution.bottom - resolution.top) == 2000)
	{
		return std::string();
	}

	return "window style borderless resolution test failed\n";
}
