#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"
#include "Resolution.h"

class WindowStyleBorderlessResolutionTest
{
public:
	WindowStyleBorderlessResolutionTest(HINSTANCE, int);
	~WindowStyleBorderlessResolutionTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

