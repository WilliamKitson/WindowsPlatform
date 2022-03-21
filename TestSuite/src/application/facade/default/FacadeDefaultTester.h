#pragma once

#include <Windows.h>
#include <string>

#include "FacadeDefaultCursorTest.h"
#include "FacadeDefaultDragTest.h"
#include "FacadeDefaultMouseTest.h"
#include "FacadeDefaultKeyboardTest.h"

class FacadeDefaultTester
{
public:
	FacadeDefaultTester(HINSTANCE, int);
	~FacadeDefaultTester();

	std::string test();


private:
	std::string testCursor();
	std::string testDrag();
	std::string testMouse();
	std::string testKeyboard();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

