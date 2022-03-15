#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowOpenPostQuitTest
{
public:
	WindowOpenPostQuitTest(HINSTANCE, int);
	~WindowOpenPostQuitTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

