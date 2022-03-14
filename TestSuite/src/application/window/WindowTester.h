#pragma once

#include <Windows.h>
#include <string>

#include "WindowDestroyedTest.h"
#include "tag/WindowTagTester.h"
#include "resolution/WindowResolutionTester.h"
#include "style/WindowStyleTester.h"
#include "event/WindowEventTester.h"

class WindowTester
{
public:
	WindowTester(HINSTANCE, int);
	~WindowTester();

	std::string test();


private:
	std::string testDestroyed();
	std::string testTag();
	std::string testResolution();
	std::string testStyle();
	std::string testEvent();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

