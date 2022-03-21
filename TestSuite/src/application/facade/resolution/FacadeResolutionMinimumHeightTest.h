#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeResolutionMinimumHeightTest
{
public:
	FacadeResolutionMinimumHeightTest(HINSTANCE, int);
	~FacadeResolutionMinimumHeightTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

