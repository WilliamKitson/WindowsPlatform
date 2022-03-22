#pragma once

#include <Windows.h>
#include <string>

#include "WindowResolutionDefaultTest.h"
#include "WindowResolutionSetTest.h"

class WindowResolutionTester
{
public:
	WindowResolutionTester(HINSTANCE, int);
	~WindowResolutionTester();

	std::string test();


private:
	std::string testDefault();
	std::string testSet();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

