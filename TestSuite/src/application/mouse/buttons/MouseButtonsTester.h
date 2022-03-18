#pragma once

#include <string>
#include "MouseButtonsPressTest.h"

class MouseButtonsTester
{
public:
	MouseButtonsTester();
	~MouseButtonsTester();

	std::string test();


private:
	std::string testPress();
};

