#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowEventCursorTest
{
public:
	WindowEventCursorTest(HINSTANCE, int);
	~WindowEventCursorTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int itterations;
	int successes;
};

