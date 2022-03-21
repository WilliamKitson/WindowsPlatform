#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeQuitEventTest
{
public:
	FacadeQuitEventTest(HINSTANCE, int);
	~FacadeQuitEventTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

