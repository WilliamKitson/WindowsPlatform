#pragma once

#include <Windows.h>
#include <string>

#include "FacadeWindowTagTest.h"
#include "FacadeWindowResolutionTest.h"
#include "FacadeWindowBorderlessTest.h"
#include "FacadeWindowWindowedTest.h"

class FacadeWindowTester
{
public:
	FacadeWindowTester(HINSTANCE, int);
	~FacadeWindowTester();

	std::string test();

private:
	std::string testTag();
	std::string testResolution();
	std::string testBorderless();
	std::string testWindowed();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
