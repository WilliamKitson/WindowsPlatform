#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowEventCursorYTest
{
public:
	WindowEventCursorYTest(HINSTANCE, int);
	~WindowEventCursorYTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

