#pragma once

#include <string>
#include "Mouse.h"

class MouseXButtonsReleaseTest
{
public:
	MouseXButtonsReleaseTest();
	~MouseXButtonsReleaseTest();

	std::string test();

private:
	int successes;
};
