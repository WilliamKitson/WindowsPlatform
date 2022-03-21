#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeStyleBorderlessResolutionTest
{
public:
	FacadeStyleBorderlessResolutionTest(HINSTANCE, int);
	~FacadeStyleBorderlessResolutionTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

