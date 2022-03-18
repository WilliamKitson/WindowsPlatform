#pragma once

#include <string>
#include "Mouse.h"

class MouseDefaultButtonsTest
{
public:
	MouseDefaultButtonsTest();
	~MouseDefaultButtonsTest();

	std::string test();


private:
	int successes;
};

