#pragma once

#include <string>

#include "MouseWheelPressTest.h"
#include "MouseWheelResetTest.h"

class MouseWheelTester
{
public:
	MouseWheelTester();
	~MouseWheelTester();

	std::string test();


private:
	std::string testPress();
	std::string testReset();
};

