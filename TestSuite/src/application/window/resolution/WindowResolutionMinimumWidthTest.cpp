#include "WindowResolutionMinimumWidthTest.h"

WindowResolutionMinimumWidthTest::WindowResolutionMinimumWidthTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowResolutionMinimumWidthTest::~WindowResolutionMinimumWidthTest()
{
}

std::string WindowResolutionMinimumWidthTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window resolution minimum width test"
	};

	unit.setResolution(WindowsPlatform::Vector2());

	RECT resolution;

	GetClientRect(
		unit.getWindow(),
		&resolution
	);

	if ((resolution.right - resolution.left) == 960)
	{
		return std::string();
	}

	return "window resolution minimum width test failed\n";
}
