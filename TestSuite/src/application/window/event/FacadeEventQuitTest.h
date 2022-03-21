#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeEventQuitTest
{
public:
	FacadeEventQuitTest(HINSTANCE, int);
	~FacadeEventQuitTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

