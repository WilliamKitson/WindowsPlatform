#include "FacadeWindowResolutionTest.h"

FacadeWindowResolutionTest::FacadeWindowResolutionTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, resolution()
{
	resolution = WindowsPlatform::Vector2{
		1000.0f,
		1000.0f
	};
}

FacadeWindowResolutionTest::~FacadeWindowResolutionTest()
{
}

std::string FacadeWindowResolutionTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window resolution test"
	);

	unit->setResolution(resolution);
	WindowsPlatform::Vector2 window = windowResolution(unit->getWindow());

	delete unit;
	unit = nullptr;

	if (window == resolution)
	{
		return std::string();
	}

	return "facade window resolution test failed\n";
}

WindowsPlatform::Vector2 FacadeWindowResolutionTest::windowResolution(HWND window)
{
	RECT windowRect;

	GetClientRect(
		window,
		&windowRect
	);

	return WindowsPlatform::Vector2{
		(float)(windowRect.right - windowRect.left),
		(float)(windowRect.bottom - windowRect.top)
	};
}
