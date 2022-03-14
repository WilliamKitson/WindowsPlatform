#pragma once

#include <string>
#include "XInputGamepad.h"

class GamepadDefaultButtonsTest
{
public:
	GamepadDefaultButtonsTest();
	~GamepadDefaultButtonsTest();

	std::string test();


private:
	int successes;
};

