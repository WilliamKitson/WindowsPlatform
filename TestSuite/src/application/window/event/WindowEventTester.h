#pragma once

#include <Windows.h>
#include <string>

#include "WindowEventQuitTest.h"
#include "WindowEventMinimiseTest.h"
#include "WindowEventCursorTest.h"
#include "WindowEventDragTest.h"
#include "WindowEventMouseTest.h"
#include "WindowEventKeyboardTest.h"

class WindowEventTester
{
public:
	WindowEventTester(HINSTANCE, int);
	~WindowEventTester();

	std::string test();


private:
	std::string testQuit();
	std::string testMinimise();
	std::string testCursor();
	std::string testDrag();
	std::string testMouse();
	std::string testKeyboard();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

