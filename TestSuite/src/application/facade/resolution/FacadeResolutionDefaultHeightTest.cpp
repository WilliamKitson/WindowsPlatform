#include "FacadeResolutionDefaultHeightTest.h"

FacadeResolutionDefaultHeightTest::FacadeResolutionDefaultHeightTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeResolutionDefaultHeightTest::~FacadeResolutionDefaultHeightTest()
{
}

std::string FacadeResolutionDefaultHeightTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade resolution default height test"
	);

	RECT resolution;

	GetClientRect(
		unit->getWindow(),
		&resolution
	);

	delete unit;
	unit = nullptr;

	if ((resolution.bottom - resolution.top) == 540)
	{
		return std::string();
	}

	return "facade resolution default height test failed\n";
}
