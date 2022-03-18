#pragma once

#include <string>
#include "MouseWheelPressTest.h"

class MouseWheelTester
{
public:
	MouseWheelTester();
	~MouseWheelTester();

	std::string test();


private:
	std::string testPress();
};

