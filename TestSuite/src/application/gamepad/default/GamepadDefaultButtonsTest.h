#pragma once

#include <string>
#include "Gamepad.h"

class GamepadDefaultButtonsTest
{
public:
	GamepadDefaultButtonsTest();
	~GamepadDefaultButtonsTest();

	std::string test();


private:
	int successes;
};

