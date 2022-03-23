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
	windowsPlatform::Vector2 windowResolution(HWND);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	windowsPlatform::Vector2 resolution;
};

