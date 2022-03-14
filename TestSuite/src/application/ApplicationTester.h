#pragma once

#include <string>

#include "delta/DeltaTester.h"
#include "gamepad/GamepadTester.h"

class ApplicationTester
{
public:
	ApplicationTester();
	~ApplicationTester();

	std::string test();


private:
	std::string testDelta();
	std::string testGamepad();
};

