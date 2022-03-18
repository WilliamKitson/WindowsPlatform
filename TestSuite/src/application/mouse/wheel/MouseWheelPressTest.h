#pragma once

#include <string>
#include "Mouse.h"

class MouseWheelPressTest
{
public:
	MouseWheelPressTest();
	~MouseWheelPressTest();

	std::string test();


private:
	int successes;
};

