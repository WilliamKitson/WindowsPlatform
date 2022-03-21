#pragma once

#include <Windows.h>
#include <string>

#include "FacadeResolutionDefaultWidthTest.h"
#include "FacadeResolutionDefaultHeightTest.h"
#include "FacadeResolutionSetWidthTest.h"
#include "FacadeResolutionSetHeightTest.h"
#include "FacadeResolutionMinimumWidthTest.h"
#include "FacadeResolutionMinimumHeightTest.h"

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

