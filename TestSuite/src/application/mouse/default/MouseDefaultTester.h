#pragma once

#include <string>

#include "MouseDefaultCursorTest.h"
#include "MouseDefaultButtonsTest.h"

class MouseDefaultTester
{
public:
	MouseDefaultTester();
	~MouseDefaultTester();

	std::string test();

private:
	std::string testCursor();
	std::string testButtons();
};
