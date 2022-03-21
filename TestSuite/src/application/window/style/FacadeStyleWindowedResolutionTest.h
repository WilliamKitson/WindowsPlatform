#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeStyleWindowedResolutionTest
{
public:
	FacadeStyleWindowedResolutionTest(HINSTANCE, int);
	~FacadeStyleWindowedResolutionTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

