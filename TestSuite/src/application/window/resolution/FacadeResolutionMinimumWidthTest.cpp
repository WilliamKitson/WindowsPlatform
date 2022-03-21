#include "FacadeResolutionMinimumWidthTest.h"

FacadeResolutionMinimumWidthTest::FacadeResolutionMinimumWidthTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeResolutionMinimumWidthTest::~FacadeResolutionMinimumWidthTest()
{
}

std::string FacadeResolutionMinimumWidthTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade resolution minimum width test"
	);

	unit->setResolution(WindowsPlatform::Vector2());

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

	return "facade resolution minimum width test failed\n";
}
