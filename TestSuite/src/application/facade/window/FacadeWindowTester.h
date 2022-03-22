#pragma once

#include <Windows.h>
#include <string>

#include "FacadeWindowTagTest.h"
#include "FacadeWindowResolutionTest.h"

class FacadeWindowTester
{
public:
	FacadeWindowTester(HINSTANCE, int);
	~FacadeWindowTester();

	std::string test();


private:
	std::string testTag();
	std::string testResolution();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

