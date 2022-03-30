#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeQuitResetTest
{
public:
	FacadeQuitResetTest(HINSTANCE, int);
	~FacadeQuitResetTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
