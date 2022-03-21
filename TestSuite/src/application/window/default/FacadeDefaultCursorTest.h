#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeDefaultCursorTest
{
public:
	FacadeDefaultCursorTest(HINSTANCE, int);
	~FacadeDefaultCursorTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

