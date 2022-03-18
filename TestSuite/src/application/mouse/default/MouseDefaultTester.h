#pragma once

#include <string>
#include "MouseDefaultCursorTest.h"

class MouseDefaultTester
{
public:
	MouseDefaultTester();
	~MouseDefaultTester();

	std::string test();


private:
	std::string testCursor();
};

