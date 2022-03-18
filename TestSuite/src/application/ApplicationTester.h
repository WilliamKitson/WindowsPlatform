#pragma once

#include <Windows.h>
#include <string>

#include "window/WindowTester.h"
#include "delta/DeltaTester.h"
#include "keyboard/KeyboardTester.h"
#include "gamepad/GamepadTester.h"

class ApplicationTester
{
public:
	ApplicationTester(HINSTANCE, int);
	~ApplicationTester();

	std::string test();


private:
	std::string testWindow();
	std::string testDelta();
	std::string testKeyboard();
	std::string testGamepad();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

