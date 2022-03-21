#include "FacadeResolutionDefaultWidthTest.h"

FacadeResolutionDefaultWidthTest::FacadeResolutionDefaultWidthTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeResolutionDefaultWidthTest::~FacadeResolutionDefaultWidthTest()
{
}

std::string FacadeResolutionDefaultWidthTest::test()
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
