#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowEventQuitTest
{
public:
	WindowEventQuitTest(HINSTANCE, int);
	~WindowEventQuitTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

