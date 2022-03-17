#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowHeightTest
{
public:
	FacadeWindowHeightTest(HINSTANCE, int);
	~FacadeWindowHeightTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const float height;
};

