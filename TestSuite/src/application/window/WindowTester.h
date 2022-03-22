#pragma once

#include <Windows.h>
#include <string>

#include "tag/WindowTagTester.h"

class WindowTester
{
public:
	WindowTester(HINSTANCE, int);
	~WindowTester();

	std::string test();


private:
	std::string testTag();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

