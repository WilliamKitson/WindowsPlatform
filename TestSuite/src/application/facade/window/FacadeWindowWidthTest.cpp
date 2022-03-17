#include "FacadeWindowWidthTest.h"

FacadeWindowWidthTest::FacadeWindowWidthTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, width{ 1000 }
{
}

FacadeWindowWidthTest::~FacadeWindowWidthTest()
{
}

std::string FacadeWindowWidthTest::test()
{
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window width test"
	);

	WindowsPlatform::Vector2 set{
		(float)width,
		0
	};

	unit->setResolution(set);

	RECT resolution;

	GetClientRect(
		unit->getWindow(),
		&resolution
	);

	delete unit;
	unit = nullptr;

	if ((resolution.right - resolution.left) == width)
	{
		return std::string();
	}

	return "facade window width test failed\n";
}
