#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeResolutionSetWidthTest
{
public:
	FacadeResolutionSetWidthTest(HINSTANCE, int);
	~FacadeResolutionSetWidthTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const int width;
};

