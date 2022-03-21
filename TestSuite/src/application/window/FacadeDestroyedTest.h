#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeDestroyedTest
{
public:
	FacadeDestroyedTest(HINSTANCE, int);
	~FacadeDestroyedTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

