#pragma once

#include <Windows.h>
#include <string>

#include "default/FacadeDefaultTester.h"
#include "tag/FacadeTagTester.h"
#include "resolution/FacadeResolutionTester.h"
#include "style/FacadeStyleTester.h"
#include "event/WindowEventTester.h"
#include "WindowDestroyedTest.h"
#include "WindowOpenPostQuitTest.h"

class WindowTester
{
public:
	WindowTester(HINSTANCE, int);
	~WindowTester();

	std::string test();


private:
	std::string testDefault();
	std::string testTag();
	std::string testResolution();
	std::string testStyle();
	std::string testEvent();
	std::string testDestroyed();
	std::string testOpenPostQuit();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

