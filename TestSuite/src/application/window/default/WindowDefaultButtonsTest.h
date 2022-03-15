#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowDefaultButtonsTest
{
public:
	WindowDefaultButtonsTest(HINSTANCE, int);
	~WindowDefaultButtonsTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

