#pragma once

#include <string>
#include "Mouse.h"

class MouseButtonsPressTest
{
public:
	MouseButtonsPressTest();
	~MouseButtonsPressTest();

	std::string test();

private:
	int successes;
};
