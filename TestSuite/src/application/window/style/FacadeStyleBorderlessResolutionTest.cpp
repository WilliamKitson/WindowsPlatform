#include "FacadeStyleBorderlessResolutionTest.h"

FacadeStyleBorderlessResolutionTest::FacadeStyleBorderlessResolutionTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeStyleBorderlessResolutionTest::~FacadeStyleBorderlessResolutionTest()
{
}

std::string FacadeStyleBorderlessResolutionTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade style borderless resolution test"
	);

	unit->setBorderless();

	WindowsPlatform::Vector2 set{
		1000,
		1000
	};

	unit->setResolution(set);

	RECT resolution;

	GetClientRect(
		unit->getWindow(),
		&resolution
	);

	delete unit;
	unit = nullptr;

	if ((resolution.right - resolution.left) + (resolution.bottom - resolution.top) == 2000)
	{
		return std::string();
	}

	return "facade style borderless resolution test failed\n";
}
