#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowResolutionDefaultHeightTest
{
public:
	WindowResolutionDefaultHeightTest(HINSTANCE, int);
	~WindowResolutionDefaultHeightTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};



