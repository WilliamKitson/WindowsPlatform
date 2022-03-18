#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeDeltaTest
{
public:
	FacadeDeltaTest(HINSTANCE, int);
	~FacadeDeltaTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

