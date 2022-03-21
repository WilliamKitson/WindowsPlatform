#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeResolutionDefaultWidthTest
{
public:
	FacadeResolutionDefaultWidthTest(HINSTANCE, int);
	~FacadeResolutionDefaultWidthTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

