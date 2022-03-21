#pragma once

#include <Windows.h>
#include <string>

#include "FacadeDefaultQuitTest.h"
#include "FacadeDefaultMinimiseTest.h"
#include "FacadeDefaultCursorTest.h"
#include "WindowDefaultDragTest.h"
#include "WindowDefaultMouseTest.h"
#include "WindowDefaultKeyboardTest.h"

class WindowDefaultTester
{
public:
	WindowDefaultTester(HINSTANCE, int);
	~WindowDefaultTester();

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

