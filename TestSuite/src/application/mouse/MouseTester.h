#pragma once

#include <string>

#include "default/MouseDefaultTester.h"
#include "buttons/MouseButtonsTester.h"
#include "xbuttons/MouseXButtonsTester.h"
#include "MouseCursorTest.h"

class MouseTester
{
public:
	MouseTester();
	~MouseTester();

	std::string test();


private:
	std::string testDefault();
	std::string testButtons();
	std::string testXButtons();
	std::string testCursor();
};

