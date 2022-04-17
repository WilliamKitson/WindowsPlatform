#pragma once

#include <Windows.h>
#include <string>

#include "Keyboard.h"

class KeyboardPressTest
{
public:
	KeyboardPressTest();
	~KeyboardPressTest();

	std::string test();

private:
	WPARAM getWparam(windowsPlatform::Keys);

private:
	int successes;
};
