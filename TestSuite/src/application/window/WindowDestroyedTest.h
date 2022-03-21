#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowDestroyedTest
{
public:
	WindowDestroyedTest(HINSTANCE, int);
	~WindowDestroyedTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

