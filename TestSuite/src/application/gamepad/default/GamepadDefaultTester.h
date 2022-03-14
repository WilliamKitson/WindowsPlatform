#pragma once

#include <string>

#include "GamepadDefaultStateTest.h"
#include "GamepadDefaultButtonsTest.h"

class GamepadDefaultTester
{
public:
	GamepadDefaultTester();
	~GamepadDefaultTester();

	std::string test();


private:
	std::string testState();
	std::string testButtons();
};

