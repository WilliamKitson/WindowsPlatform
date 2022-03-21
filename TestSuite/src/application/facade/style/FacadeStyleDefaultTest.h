#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeStyleDefaultTest
{
public:
	FacadeStyleDefaultTest(HINSTANCE, int);
	~FacadeStyleDefaultTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

