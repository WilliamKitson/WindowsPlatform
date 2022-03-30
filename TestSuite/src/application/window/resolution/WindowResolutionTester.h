#pragma once

#include <Windows.h>
#include <string>

#include "WindowResolutionDefaultTest.h"
#include "WindowResolutionSetTest.h"
#include "WindowResolutionMinimumTest.h"

class WindowResolutionTester
{
public:
	WindowResolutionTester(HINSTANCE, int);
	~WindowResolutionTester();

	std::string test();

private:
	std::string testDefault();
	std::string testSet();
	std::string testMinimum();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
