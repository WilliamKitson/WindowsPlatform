#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowWidthTest
{
public:
	FacadeWindowWidthTest(HINSTANCE, int);
	~FacadeWindowWidthTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const int width;
};

