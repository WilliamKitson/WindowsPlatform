#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowResolutionMinimumWidthTest
{
public:
	WindowResolutionMinimumWidthTest(HINSTANCE, int);
	~WindowResolutionMinimumWidthTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

