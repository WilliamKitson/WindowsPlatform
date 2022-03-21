#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeQuitDefaultTest
{
public:
	FacadeQuitDefaultTest(HINSTANCE, int);
	~FacadeQuitDefaultTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

