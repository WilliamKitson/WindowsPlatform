#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowDefaultKeyboardTest
{
public:
	WindowDefaultKeyboardTest(HINSTANCE, int);
	~WindowDefaultKeyboardTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

