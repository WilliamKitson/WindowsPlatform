#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeMinimiseEventTest
{
public:
	FacadeMinimiseEventTest(HINSTANCE, int);
	~FacadeMinimiseEventTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

