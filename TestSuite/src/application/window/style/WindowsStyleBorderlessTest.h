#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateImplimentation.h"

class WindowsStyleBorderlessTest
{
public:
	WindowsStyleBorderlessTest(HINSTANCE, int);
	~WindowsStyleBorderlessTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

