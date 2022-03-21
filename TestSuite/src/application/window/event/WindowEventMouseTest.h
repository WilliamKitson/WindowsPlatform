#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateImplimentation.h"

class WindowEventMouseTest
{
public:
	WindowEventMouseTest(HINSTANCE, int);
	~WindowEventMouseTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

