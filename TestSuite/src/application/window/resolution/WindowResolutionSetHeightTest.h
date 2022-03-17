#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowResolutionSetHeightTest
{
public:
	WindowResolutionSetHeightTest(HINSTANCE, int);
	~WindowResolutionSetHeightTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const int height;
};

