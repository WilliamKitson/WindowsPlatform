#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowEventDragYTest
{
public:
	WindowEventDragYTest(HINSTANCE, int);
	~WindowEventDragYTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

