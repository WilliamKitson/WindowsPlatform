#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeStyleWindowedTest
{
public:
	FacadeStyleWindowedTest(HINSTANCE, int);
	~FacadeStyleWindowedTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

