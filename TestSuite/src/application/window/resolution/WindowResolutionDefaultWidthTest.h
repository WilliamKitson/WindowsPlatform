#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowResolutionDefaultWidthTest
{
public:
	WindowResolutionDefaultWidthTest(HINSTANCE, int);
	~WindowResolutionDefaultWidthTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

