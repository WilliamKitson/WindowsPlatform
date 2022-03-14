#pragma once

#include <string>

#include "mouseState/MouseStateTester.h"
#include "gamepadState/GamepadStateTester.h"
#include "vibration/VibrationTester.h"

class PresentationTester
{
public:
	PresentationTester();
	~PresentationTester();

	std::string test();


private:
	std::string testResolution();
	std::string testMouseState();
	std::string testGamepadState();
	std::string testVibration();
};

