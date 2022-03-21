#include "WindowStyleWindowedResolutionTest.h"

WindowStyleWindowedResolutionTest::WindowStyleWindowedResolutionTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowStyleWindowedResolutionTest::~WindowStyleWindowedResolutionTest()
{
}

std::string WindowStyleWindowedResolutionTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade style windowed resolution test"
	);

	unit->setBorderless();
	unit->setWindowed();

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

	return "facade style windowed resolution test failed\n";
}
