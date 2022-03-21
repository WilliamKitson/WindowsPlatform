#include "WindowResolutionSetWidthTest.h"

WindowsResolutionSetWidthTest::WindowsResolutionSetWidthTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, width{ 1000 }
{
}

WindowsResolutionSetWidthTest::~WindowsResolutionSetWidthTest()
{
}

std::string WindowsResolutionSetWidthTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade resolution set width test"
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

	return "facade resolution set width test failed\n";
}
