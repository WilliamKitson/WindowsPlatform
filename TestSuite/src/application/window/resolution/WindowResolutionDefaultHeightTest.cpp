#include "WindowResolutionDefaultHeightTest.h"

WindowResolutionDefaultHeightTest::WindowResolutionDefaultHeightTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowResolutionDefaultHeightTest::~WindowResolutionDefaultHeightTest()
{
}

std::string WindowResolutionDefaultHeightTest::test()
{
	WindowsPlatform::SubordinateImplimentation unit{
		hInstance,
		nCmdShow,
		"window resolution default height test"
	};

	RECT resolution;

	GetClientRect(
		unit.getWindow(),
		&resolution
	);

	if ((resolution.bottom - resolution.top) == 540)
	{
		return std::string();
	}

	return "window resolution default height test failed\n";
}
