#pragma once

#include <Windows.h>
#include <string>

#include "FacadeWindowQuitTest.h"

class FacadeWindowTester
{
public:
	FacadeWindowTester(HINSTANCE, int);
	~FacadeWindowTester();

	std::string test();


private:
	std::string testQuit();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

