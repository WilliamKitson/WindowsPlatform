#pragma once

#include <Windows.h>
#include <string>

#include "FacadeStyleDefaultTest.h"
#include "FacadeStyleBorderlessTest.h"
#include "FacadeStyleBorderlessResolutionTest.h"
#include "FacadeStyleWindowedTest.h"
#include "WindowStyleWindowedResolutionTest.h"

class WindowStyleTester
{
public:
	WindowStyleTester(HINSTANCE, int);
	~WindowStyleTester();

	std::string test();


private:
	std::string testDefault();
	std::string testBorderless();
	std::string testBorderlessResolution();
	std::string testWindowed();
	std::string testWindowedResolution();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

