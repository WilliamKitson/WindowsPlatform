#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowResolutionTest
{
public:
	FacadeWindowResolutionTest(HINSTANCE, int);
	~FacadeWindowResolutionTest();

	std::string test();


private:
	WindowsPlatform::Vector2 windowResolution(HWND);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	WindowsPlatform::Vector2 resolution;
};

