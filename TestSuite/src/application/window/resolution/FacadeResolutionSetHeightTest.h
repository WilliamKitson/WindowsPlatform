#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeResolutionSetHeightTest
{
public:
	FacadeResolutionSetHeightTest(HINSTANCE, int);
	~FacadeResolutionSetHeightTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const int height;
};

