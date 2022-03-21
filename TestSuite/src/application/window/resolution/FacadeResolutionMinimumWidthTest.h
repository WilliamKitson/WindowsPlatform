#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeResolutionMinimumWidthTest
{
public:
	FacadeResolutionMinimumWidthTest(HINSTANCE, int);
	~FacadeResolutionMinimumWidthTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

