#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowResolutionDefaultWidthTest
{
public:
	WindowResolutionDefaultWidthTest(HINSTANCE, int);
	~WindowResolutionDefaultWidthTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

