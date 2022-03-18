#pragma once

#include <string>

#include "KeyboardDefaultTest.h"
#include "KeyboardPressTest.h"

class KeyboardTester
{
public:
	KeyboardTester();
	~KeyboardTester();

	std::string test();


private:
	std::string testDefault();
	std::string testPress();
};

