#pragma once

#include <Windows.h>
#include <string>

#include "WindowStyleDefaultTest.h"
#include "WindowStyleBorderlessTest.h"

class WindowStyleTester
{
public:
	WindowStyleTester(HINSTANCE, int);
	~WindowStyleTester();

	std::string test();


private:
	std::string testDefault();
	std::string testBorderless();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

