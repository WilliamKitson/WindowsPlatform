#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowResolutionMinimumHeightTest
{
public:
	WindowResolutionMinimumHeightTest(HINSTANCE, int);
	~WindowResolutionMinimumHeightTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

