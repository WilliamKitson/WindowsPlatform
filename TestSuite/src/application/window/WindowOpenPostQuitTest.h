#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowOpenPostQuitTest
{
public:
	WindowOpenPostQuitTest(HINSTANCE, int);
	~WindowOpenPostQuitTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

