#pragma once

#include <Windows.h>
#include <string>

#include "WindowDefaultQuitTest.h"

class WindowDefaultTester
{
public:
	WindowDefaultTester(HINSTANCE, int);
	~WindowDefaultTester();

	std::string test();


private:
	std::string testQuit();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

