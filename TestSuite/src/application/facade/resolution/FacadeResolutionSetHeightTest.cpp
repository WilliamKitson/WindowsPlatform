#include "FacadeResolutionSetHeightTest.h"

FacadeResolutionSetHeightTest::FacadeResolutionSetHeightTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, height{ 1000 }
{
}

FacadeResolutionSetHeightTest::~FacadeResolutionSetHeightTest()
{
}

std::string FacadeResolutionSetHeightTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade resolution set height test"
	);

	WindowsPlatform::Vector2 set{
		0,
		(float)height
	};

	unit->setResolution(set);

	RECT resolution;

	GetClientRect(
		unit->getWindow(),
		&resolution
	);

	delete unit;
	unit = nullptr;

	if ((resolution.bottom - resolution.top) == height)
	{
		return std::string();
	}

	return "facade resolution set height test failed\n";
}
