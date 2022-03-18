#pragma once

#include <string>
#include "Mouse.h"

class MouseWheelResetTest
{
public:
	MouseWheelResetTest();
	~MouseWheelResetTest();

	std::string test();


private:
	int successes;
};

