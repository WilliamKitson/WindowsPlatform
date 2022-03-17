#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowMinimiseTest
{
public:
	FacadeWindowMinimiseTest(HINSTANCE, int);
	~FacadeWindowMinimiseTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

