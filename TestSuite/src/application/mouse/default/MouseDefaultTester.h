#pragma once

#include <string>

#include "MouseDefaultCursorTest.h"
#include "MouseDefaultDragTest.h"
#include "MouseDefaultButtonsTest.h"

class MouseDefaultTester
{
public:
	MouseDefaultTester();
	~MouseDefaultTester();

	std::string test();


private:
	std::string testCursor();
	std::string testDrag();
	std::string testButtons();
};

