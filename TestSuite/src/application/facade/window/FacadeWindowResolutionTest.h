#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Facade.h"
#include "Implimentation.h"

class FacadeWindowResolutionTest
{
public:
	FacadeWindowResolutionTest(HINSTANCE, int);
	~FacadeWindowResolutionTest();

	std::string test();

private:
	windowsPlatform::Vector2 windowResolution(HWND);
	bool success(windowsPlatform::Vector2);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	windowsPlatform::Facade* unit;
	windowsPlatform::Vector2 resolution;
};
