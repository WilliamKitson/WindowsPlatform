#pragma once

#include <Windows.h>
#include <string>

#include "FacadeWindowTagTest.h"

class FacadeWindowTester
{
public:
	FacadeWindowTester(HINSTANCE, int);
	~FacadeWindowTester();

	std::string test();


private:
	std::string testTag();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

