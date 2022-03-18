#include "FacadeWindowResolutionTest.h"

FacadeWindowResolutionTest::FacadeWindowResolutionTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeWindowResolutionTest::~FacadeWindowResolutionTest()
{
}

std::string FacadeWindowResolutionTest::test()
{
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window resolution test"
	);

	WindowsPlatform::Vector2 set{
		1000.0f,
		1000.0f
	};

	unit->setResolution(set);

	RECT resolution;

	GetClientRect(
		unit->getWindow(),
		&resolution
	);

	delete unit;
	unit = nullptr;

	WindowsPlatform::Vector2 get{
		(float)(resolution.right - resolution.left),
		(float)(resolution.bottom - resolution.top)
	};

	if (get == set)
	{
		return std::string();
	}

	return "facade window resolution test failed\n";
}
