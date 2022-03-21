#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowStyleWindowedResolutionTest
{
public:
	WindowStyleWindowedResolutionTest(HINSTANCE, int);
	~WindowStyleWindowedResolutionTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

