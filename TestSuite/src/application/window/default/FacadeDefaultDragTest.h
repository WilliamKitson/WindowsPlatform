#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeDefaultDragTest
{
public:
	FacadeDefaultDragTest(HINSTANCE, int);
	~FacadeDefaultDragTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

