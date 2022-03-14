#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowEventDragXTest
{
public:
	WindowEventDragXTest(HINSTANCE, int);
	~WindowEventDragXTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

