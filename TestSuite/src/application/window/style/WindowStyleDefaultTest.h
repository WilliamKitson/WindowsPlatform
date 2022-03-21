#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowStyleDefaultTest
{
public:
	WindowStyleDefaultTest(HINSTANCE, int);
	~WindowStyleDefaultTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

