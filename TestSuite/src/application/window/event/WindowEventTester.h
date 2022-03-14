#pragma once

#include <Windows.h>
#include <string>

#include "WindowEventCursorXTest.h"
#include "WindowEventCursorYTest.h"
#include "WindowEventDragXTest.h"
#include "WindowEventDragYTest.h"
#include "WindowEventButtonsTest.h"
#include "WindowEventQuitTest.h"
#include "WindowEventOpenPostQuit.h"
#include "WindowEventMinimiseTest.h"

class WindowEventTester
{
public:
	WindowEventTester(HINSTANCE, int);
	~WindowEventTester();

	std::string test();


private:
	std::string testCursorX();
	std::string testCursorY();
	std::string testDragX();
	std::string testDragY();
	std::string testButtons();
	std::string testQuit();
	std::string testOpenPostQuit();
	std::string testMinimise();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

