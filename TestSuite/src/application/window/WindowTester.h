#pragma once

#include <Windows.h>
#include <string>

#include "tag/WindowTagTester.h"
#include "resolution/WindowResolutionTester.h"

class WindowTester
{
public:
	WindowTester(HINSTANCE, int);
	~WindowTester();

	std::string test();


private:
	std::string testTag();
	std::string testResolution();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

