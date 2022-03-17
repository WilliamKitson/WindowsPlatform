#pragma once

#include <string>
#include "GamepadDefaultJoystickLeftTest.h"

class GamepadDefaultTester
{
public:
	GamepadDefaultTester();
	~GamepadDefaultTester();

	std::string test();


private:
	std::string testJoystickLeft();
};

