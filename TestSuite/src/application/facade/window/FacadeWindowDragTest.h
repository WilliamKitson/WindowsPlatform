#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowDragTest
{
public:
	FacadeWindowDragTest(HINSTANCE, int);
	~FacadeWindowDragTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::string tagPrefix;
};

