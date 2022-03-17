#pragma once

#include <string>

#include "GamepadDefaultJoystickLeftTest.h"
#include "GamepadDefaultJoystickRightTest.h"
#include "GamepadDefaultTriggerLeftTest.h"

class GamepadDefaultTester
{
public:
	GamepadDefaultTester();
	~GamepadDefaultTester();

	std::string test();


private:
	std::string testJoystickLeft();
	std::string testJoystickRight();
	std::string testTriggerLeft();
};

