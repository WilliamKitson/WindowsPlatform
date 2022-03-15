#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowDefaultMouseTest
{
public:
	WindowDefaultMouseTest(HINSTANCE, int);
	~WindowDefaultMouseTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

