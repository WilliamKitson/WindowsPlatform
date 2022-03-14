#include "WindowResolutionDefaultWidthTest.h"

WindowResolutionDefaultWidthTest::WindowResolutionDefaultWidthTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowResolutionDefaultWidthTest::~WindowResolutionDefaultWidthTest()
{
}

std::string WindowResolutionDefaultWidthTest::test()
{
	ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window resolution default width test"
	};

	RECT resolution;

	GetClientRect(
		unit.getWindow(),
		&resolution
	);

	if ((resolution.right - resolution.left) == 960)
	{
		return std::string();
	}

	return "window resolution default test failed\n";
}
