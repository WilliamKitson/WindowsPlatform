#pragma once

#include <string>
#include "default/GamepadDefaultTester.h"

class GamepadTester
{
public:
	GamepadTester();
	~GamepadTester();

	std::string test();

private:
	std::string testDefault();
};
