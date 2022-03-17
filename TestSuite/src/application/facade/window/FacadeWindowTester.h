#pragma once

#include <Windows.h>
#include <string>

#include "FacadeWindowQuitTest.h"
#include "FacadeWindowMinimiseTest.h"
#include "FacadeWindowCursorTest.h"

class FacadeWindowTester
{
public:
	FacadeWindowTester(HINSTANCE, int);
	~FacadeWindowTester();

	std::string test();


private:
	std::string testQuit();
	std::string testMinimise();
	std::string testCursor();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

