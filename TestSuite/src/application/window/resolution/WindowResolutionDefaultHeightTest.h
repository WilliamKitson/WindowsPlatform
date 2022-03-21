#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowResolutionDefaultHeightTest
{
public:
	WindowResolutionDefaultHeightTest(HINSTANCE, int);
	~WindowResolutionDefaultHeightTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};



