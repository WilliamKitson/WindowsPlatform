#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeDefaultMouseTest
{
public:
	FacadeDefaultMouseTest(HINSTANCE, int);
	~FacadeDefaultMouseTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

