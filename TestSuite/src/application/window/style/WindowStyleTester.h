#pragma once

#include <Windows.h>
#include <string>

#include "WindowStyleDefaultTest.h"

class WindowStyleTester
{
public:
	WindowStyleTester(HINSTANCE, int);
	~WindowStyleTester();

	std::string test();


private:
	std::string testDefault();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

