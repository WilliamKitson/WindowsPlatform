#pragma once

#include <Windows.h>
#include <string>

#include "Keyboard.h"

class KeyboardReleaseTest
{
public:
	KeyboardReleaseTest();
	~KeyboardReleaseTest();

	std::string test();

private:
	WPARAM getWparam(windowsPlatform::KeyboardKeys);

private:
	int successes;
};
