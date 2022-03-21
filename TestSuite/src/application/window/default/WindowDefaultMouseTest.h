#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateImplimentation.h"

class WindowDefaultMouseTest
{
public:
	WindowDefaultMouseTest(HINSTANCE, int);
	~WindowDefaultMouseTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

