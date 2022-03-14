#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowEventButtonsTest
{
public:
	WindowEventButtonsTest(HINSTANCE, int);
	~WindowEventButtonsTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

