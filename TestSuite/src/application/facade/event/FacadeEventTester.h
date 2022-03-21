#pragma once

#include <Windows.h>
#include <string>

#include "FacadeEventCursorTest.h"
#include "FacadeEventDragTest.h"
#include "FacadeEventMouseTest.h"
#include "FacadeEventKeyboardTest.h"

class FacadeEventTester
{
public:
	FacadeEventTester(HINSTANCE, int);
	~FacadeEventTester();

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

