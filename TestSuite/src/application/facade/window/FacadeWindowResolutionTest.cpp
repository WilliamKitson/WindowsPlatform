#include "FacadeWindowResolutionTest.h"

FacadeWindowResolutionTest::FacadeWindowResolutionTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, resolution()
{
	resolution = windowsPlatform::Vector2{
		1000.0f,
		1000.0f
	};
}

FacadeWindowResolutionTest::~FacadeWindowResolutionTest()
{
}

std::string FacadeWindowResolutionTest::test()
{
	windowsPlatform::Facade* unit = new windowsPlatform::Implimentation(
		hInstance,
		nCmdShow,
		"facade window resolution test"
	);

	unit->setResolution(resolution);
	windowsPlatform::Vector2 window = windowResolution(unit->getWindow());

	delete unit;
	unit = nullptr;

	bool successes = true;

	if (window.x != resolution.x)
	{
		successes = false;
	}

	if (window.y != resolution.y)
	{
		successes = false;
	}

	if (successes)
	{
		return std::string();
	}

	return "facade window resolution test failed\n";
}

windowsPlatform::Vector2 FacadeWindowResolutionTest::windowResolution(HWND window)
{
	RECT windowRect;

	GetClientRect(
		window,
		&windowRect
	);

	return windowsPlatform::Vector2{
		(float)(windowRect.right - windowRect.left),
		(float)(windowRect.bottom - windowRect.top)
	};
}
