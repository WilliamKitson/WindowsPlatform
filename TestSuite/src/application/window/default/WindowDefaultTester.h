#pragma once

#include <Windows.h>
#include <string>

#include "WindowDefaultQuitTest.h"
#include "WindowDefaultMinimiseTest.h"
#include "WindowDefaultMouseTest.h"

class WindowDefaultTester
{
public:
	WindowDefaultTester(HINSTANCE, int);
	~WindowDefaultTester();

	std::string test();


private:
	std::string testQuit();
	std::string testMinimise();
	std::string testMouse();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

