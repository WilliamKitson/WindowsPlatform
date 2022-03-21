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
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade resolution default width test"
	);

	RECT resolution;

	GetClientRect(
		unit->getWindow(),
		&resolution
	);

	delete unit;
	unit = nullptr;

	if ((resolution.right - resolution.left) == 960)
	{
		return std::string();
	}

	return "facade resolution default test failed\n";
}
