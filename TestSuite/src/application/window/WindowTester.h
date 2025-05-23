#pragma once

#include <Windows.h>
#include <string>

#include "tag/WindowTagTester.h"
#include "resolution/WindowResolutionTester.h"
#include "style/WindowStyleTester.h"
#include "WindowDestoryedTest.h"

class WindowTester
{
public:
	WindowTester(HINSTANCE, int);
	~WindowTester();

	std::string test();

private:
	std::string testTag();
	std::string testResolution();
	std::string testStyle();
	std::string testDestroyed();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
