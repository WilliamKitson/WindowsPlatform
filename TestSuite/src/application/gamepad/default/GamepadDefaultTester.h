#pragma once

#include <string>
#include "GamepadDefaultStateTest.h"

class GamepadDefaultTester
{
public:
	GamepadDefaultTester();
	~GamepadDefaultTester();

	std::string test();


private:
	std::string testState();
};

