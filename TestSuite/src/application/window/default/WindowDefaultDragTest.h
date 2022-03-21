#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateImplimentation.h"

class WindowDefaultDragTest
{
public:
	WindowDefaultDragTest(HINSTANCE, int);
	~WindowDefaultDragTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

