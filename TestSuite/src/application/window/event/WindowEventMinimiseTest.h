#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateImplimentation.h"

class WindowEventMinimiseTest
{
public:
	WindowEventMinimiseTest(HINSTANCE, int);
	~WindowEventMinimiseTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

