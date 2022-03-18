#pragma once

#include <Windows.h>
#include <string>

#include "window/FacadeWindowTester.h"
#include "FacadeDeltaTest.h"

class FacadeTester
{
public:
	FacadeTester(HINSTANCE, int);
	~FacadeTester();

	std::string test();


private:
	std::string testWindow();
	std::string testDelta();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

