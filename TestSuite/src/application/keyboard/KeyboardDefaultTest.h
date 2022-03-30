#pragma once

#include <string>
#include "Keyboard.h"

class KeyboardDefaultTest
{
public:
	KeyboardDefaultTest();
	~KeyboardDefaultTest();

	std::string test();

private:
	int successes;
};
