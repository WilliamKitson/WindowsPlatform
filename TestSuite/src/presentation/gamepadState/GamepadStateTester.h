#pragma once

#include <string>

#include "GamepadStateDefaultTest.h"
#include "GamepadStateJoystickLXTest.h"
#include "GamepadStateJoystickLYTest.h"
#include "GamepadStateJoystickRXTest.h"

class GamepadStateTester
{
public:
	GamepadStateTester();
	~GamepadStateTester();

	std::string test();


private:
	std::string testDefault();
	std::string testJoystickLX();
	std::string testJoystickLY();
	std::string testJoystickRX();
};

