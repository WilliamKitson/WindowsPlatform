#pragma once

#include <string>
#include "GamepadStateDefaultTest.h"

class GamepadStateTester
{
public:
	GamepadStateTester();
	~GamepadStateTester();

	std::string test();


private:
	std::string testDefault();
};

