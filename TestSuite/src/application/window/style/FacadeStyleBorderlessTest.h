#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeStyleBorderlessTest
{
public:
	FacadeStyleBorderlessTest(HINSTANCE, int);
	~FacadeStyleBorderlessTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

