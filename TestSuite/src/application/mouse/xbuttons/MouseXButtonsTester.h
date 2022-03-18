#pragma once

#include <string>
#include "MouseXButtonsPressTest.h"

class MouseXButtonsTester
{
public:
	MouseXButtonsTester();
	~MouseXButtonsTester();

	std::string test();


private:
	std::string testPress();
};

