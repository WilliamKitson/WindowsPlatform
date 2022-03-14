#pragma once

#include <string>

#include "GamepadStateDefaultTest.h"
#include "GamepadStateJoystickLXTest.h"

class GamepadStateTester
{
public:
	GamepadStateTester();
	~GamepadStateTester();

	std::string test();


private:
	std::string testDefault();
	std::string testJoystickLX();
};

