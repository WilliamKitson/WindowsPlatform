#pragma once

#include <Windows.h>
#include <string>

#include "window/FacadeWindowTester.h"

class FacadeTester
{
public:
	FacadeTester(HINSTANCE, int);
	~FacadeTester();

	std::string test();


private:
	std::string testWindow();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

