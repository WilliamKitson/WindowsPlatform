#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateImplimentation.h"

class WindowDefaultMinimiseTest
{
public:
	WindowDefaultMinimiseTest(HINSTANCE, int);
	~WindowDefaultMinimiseTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

