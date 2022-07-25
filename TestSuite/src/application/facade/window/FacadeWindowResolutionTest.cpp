#include "FacadeWindowResolutionTest.h"

FacadeWindowResolutionTest::FacadeWindowResolutionTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, unit{ new windowsPlatform::Implimentation(hInstance, nCmdShow, "facade window resolution test") }, resolution()
{
	resolution = windowsPlatform::Vector2{
		1000.0f,
		1000.0f
	};
}

FacadeWindowResolutionTest::~FacadeWindowResolutionTest()
{
	delete unit;
	unit = nullptr;
}

std::string FacadeWindowResolutionTest::test()
{
	unit->setResolution(resolution);

	if (success(windowResolution(unit->getWindow())))
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

bool FacadeWindowResolutionTest::success(windowsPlatform::Vector2 input)
{
	if (input.x != resolution.x)
	{
		return false;
	}

	if (input.y != resolution.y)
	{
		return false;
	}

	return true;
}
