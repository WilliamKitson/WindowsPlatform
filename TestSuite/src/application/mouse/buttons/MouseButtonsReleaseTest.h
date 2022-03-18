#pragma once

#include <string>
#include "Mouse.h"

class MouseButtonsReleaseTest
{
public:
	MouseButtonsReleaseTest();
	~MouseButtonsReleaseTest();

	std::string test();


private:
	int successes;
};

