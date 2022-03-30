#pragma once

#include <string>

#include "MouseButtonsPressTest.h"
#include "MouseButtonsReleaseTest.h"

class MouseButtonsTester
{
public:
	MouseButtonsTester();
	~MouseButtonsTester();

	std::string test();

private:
	std::string testPress();
	std::string testRelease();
};
