#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowsResolutionSetWidthTest
{
public:
	WindowsResolutionSetWidthTest(HINSTANCE, int);
	~WindowsResolutionSetWidthTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const int width;
};

