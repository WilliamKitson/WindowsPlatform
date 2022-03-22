#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowWindowedTest
{
public:
	FacadeWindowWindowedTest(HINSTANCE, int);
	~FacadeWindowWindowedTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

