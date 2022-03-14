#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowEventCursorXTest
{
public:
	WindowEventCursorXTest(HINSTANCE, int);
	~WindowEventCursorXTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

