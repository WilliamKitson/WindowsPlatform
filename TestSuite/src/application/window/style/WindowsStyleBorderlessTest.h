#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

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

