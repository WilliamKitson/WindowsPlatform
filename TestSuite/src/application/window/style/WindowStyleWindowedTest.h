#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateImplimentation.h"

class WindowStyleWindowedTest
{
public:
	WindowStyleWindowedTest(HINSTANCE, int);
	~WindowStyleWindowedTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

