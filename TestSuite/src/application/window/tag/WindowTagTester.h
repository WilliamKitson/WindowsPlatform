#pragma once

#include <Windows.h>
#include <string>

#include "WindowTagInitialiseTest.h"

class WindowTagTester
{
public:
	WindowTagTester(HINSTANCE, int);
	~WindowTagTester();

	std::string test();


private:
	std::string testInitialise();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

