#pragma once

#include <string>
#include "KeyboardDefaultTest.h"

class KeyboardTester
{
public:
	KeyboardTester();
	~KeyboardTester();

	std::string test();


private:
	std::string testDefault();
};

