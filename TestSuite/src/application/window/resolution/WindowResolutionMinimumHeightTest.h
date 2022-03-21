#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowResolutionMinimumHeightTest
{
public:
	WindowResolutionMinimumHeightTest(HINSTANCE, int);
	~WindowResolutionMinimumHeightTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

