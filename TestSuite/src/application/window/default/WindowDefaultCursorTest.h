#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

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

