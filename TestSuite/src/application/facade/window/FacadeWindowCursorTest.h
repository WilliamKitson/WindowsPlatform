#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowCursorTest
{
public:
	FacadeWindowCursorTest(HINSTANCE, int);
	~FacadeWindowCursorTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

