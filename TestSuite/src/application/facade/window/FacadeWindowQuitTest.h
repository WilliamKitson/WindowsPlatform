#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowQuitTest
{
public:
	FacadeWindowQuitTest(HINSTANCE, int);
	~FacadeWindowQuitTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

