#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowEventOpenPostQuitTest
{
public:
	WindowEventOpenPostQuitTest(HINSTANCE, int);
	~WindowEventOpenPostQuitTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

