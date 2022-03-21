#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeOpenPostQuitTest
{
public:
	FacadeOpenPostQuitTest(HINSTANCE, int);
	~FacadeOpenPostQuitTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

