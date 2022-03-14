#include "WindowResolutionMinimumHeightTest.h"

WindowResolutionMinimumHeightTest::WindowResolutionMinimumHeightTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowResolutionMinimumHeightTest::~WindowResolutionMinimumHeightTest()
{
}

std::string WindowResolutionMinimumHeightTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window resolution minimum height test"
	};

	unit.setResolution(0, 0);

	RECT resolution;

	GetClientRect(
		unit.getWindow(),
		&resolution
	);

	if ((resolution.bottom - resolution.top) == 540)
	{
		return std::string();
	}

	return "window resolution minimum height test failed\n";
}
