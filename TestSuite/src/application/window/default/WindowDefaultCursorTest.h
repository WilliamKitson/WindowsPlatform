#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateImplimentation.h"

class WindowDefaultCursorTest
{
public:
	WindowDefaultCursorTest(HINSTANCE, int);
	~WindowDefaultCursorTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

