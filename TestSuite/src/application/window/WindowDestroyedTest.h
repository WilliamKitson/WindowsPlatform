#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "ApplicationWindow.h"

class WindowDestoroyedTest
{
public:
	WindowDestoroyedTest(HINSTANCE, int);
	~WindowDestoroyedTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

