#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeEventMinimiseTest
{
public:
	FacadeEventMinimiseTest(HINSTANCE, int);
	~FacadeEventMinimiseTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

