#pragma once

#include <string>

#include "MouseXButtonsPressTest.h"
#include "MouseXButtonsReleaseTest.h"

class MouseXButtonsTester
{
public:
	MouseXButtonsTester();
	~MouseXButtonsTester();

	std::string test();


private:
	std::string testPress();
	std::string testRelease();
};

