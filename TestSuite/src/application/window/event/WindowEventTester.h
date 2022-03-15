#pragma once

#include <Windows.h>
#include <string>

#include "WindowEventQuitTest.h"
#include "WindowEventOpenPostQuit.h"
#include "WindowEventMinimiseTest.h"
#include "WindowEventCursorTest.h"
#include "WindowEventButtonsTest.h"
#include "WindowEventKeysTest.h"

class WindowEventTester
{
public:
	WindowEventTester(HINSTANCE, int);
	~WindowEventTester();

	std::string test();


private:
	std::string testQuit();
	std::string testOpenPostQuit();
	std::string testMinimise();
	std::string testCursor();
	std::string testButtons();
	std::string testKeys();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

