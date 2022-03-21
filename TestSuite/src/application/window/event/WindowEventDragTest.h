#pragma once

#include <Windows.h>
#include <string>

#include "WindowEventDragTest.h"
#include "SubordinateImplimentation.h"

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

