#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "ApplicationWindow.h"

class WindowDefaultQuitTest
{
public:
	WindowDefaultQuitTest(HINSTANCE, int);
	~WindowDefaultQuitTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

