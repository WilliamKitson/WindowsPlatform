#pragma once

#include <Windows.h>
#include <string>

#include "WindowStyleDefaultTest.h"
#include "WindowStyleBorderlessTest.h"
#include "WindowStyleWindowedTest.h"

class WindowStyleTester
{
public:
	WindowStyleTester(HINSTANCE, int);
	~WindowStyleTester();

	std::string test();


private:
	std::string testDefault();
	std::string testBorderless();
	std::string testWindowed();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

