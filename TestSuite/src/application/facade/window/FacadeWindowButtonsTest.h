#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowButtonsTest
{
public:
	FacadeWindowButtonsTest(HINSTANCE, int);
	~FacadeWindowButtonsTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

