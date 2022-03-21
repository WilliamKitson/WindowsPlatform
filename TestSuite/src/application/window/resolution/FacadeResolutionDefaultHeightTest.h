#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeResolutionDefaultHeightTest
{
public:
	FacadeResolutionDefaultHeightTest(HINSTANCE, int);
	~FacadeResolutionDefaultHeightTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};



