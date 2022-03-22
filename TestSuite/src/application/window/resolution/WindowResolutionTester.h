#pragma once

#include <Windows.h>
#include <string>

#include "WindowResolutionDefaultTest.h"

class WindowResolutionTester
{
public:
	WindowResolutionTester(HINSTANCE, int);
	~WindowResolutionTester();

	std::string test();


private:
	std::string testDefault();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

