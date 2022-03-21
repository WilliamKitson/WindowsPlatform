#include "FacadeResolutionMinimumHeightTest.h"

FacadeResolutionMinimumHeightTest::FacadeResolutionMinimumHeightTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeResolutionMinimumHeightTest::~FacadeResolutionMinimumHeightTest()
{
}

std::string FacadeResolutionMinimumHeightTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade resolution minimum height test"
	);

	unit->setResolution(WindowsPlatform::Vector2());

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

	return "facade resolution minimum height test failed\n";
}
