#include "FacadeWindowHeightTest.h"

FacadeWindowHeightTest::FacadeWindowHeightTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, height{ 1000 }
{
}

FacadeWindowHeightTest::~FacadeWindowHeightTest()
{
}

std::string FacadeWindowHeightTest::test()
{
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window height test"
	);

	WindowsPlatform::Vector2 set{
		0.0f,
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

	return "facade window height test failed\n";
}
