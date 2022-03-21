#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeDefaultMinimiseTest
{
public:
	FacadeDefaultMinimiseTest(HINSTANCE, int);
	~FacadeDefaultMinimiseTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

