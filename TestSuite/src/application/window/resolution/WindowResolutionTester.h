#pragma once

#include <Windows.h>
#include <string>

#include "FacadeResolutionDefaultWidthTest.h"
#include "WindowResolutionDefaultHeightTest.h"
#include "WindowResolutionSetWidthTest.h"
#include "WindowResolutionSetHeightTest.h"
#include "WindowResolutionMinimumWidthTest.h"
#include "WindowResolutionMinimumHeightTest.h"

class WindowResolutionTester
{
public:
	WindowResolutionTester(HINSTANCE, int);
	~WindowResolutionTester();

	std::string test();


private:
	std::string testDefaultWidth();
	std::string testDefaultHeight();
	std::string testSetWidth();
	std::string testSetHeight();
	std::string testMinimumWidth();
	std::string testMinimumHeight();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

