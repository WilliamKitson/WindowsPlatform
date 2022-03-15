#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowEventDragTest
{
public:
	WindowEventDragTest(HINSTANCE, int);
	~WindowEventDragTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::string tagPrefix;
};

