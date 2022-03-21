#pragma once

#include <Windows.h>
#include <string>

#include "delta/DeltaTester.h"
#include "mouse/MouseTester.h"
#include "keyboard/KeyboardTester.h"
#include "gamepad/GamepadTester.h"
#include "window/FacadeTester.h"

class ApplicationTester
{
public:
	ApplicationTester(HINSTANCE, int);
	~ApplicationTester();

	std::string test();


private:
	std::string testDelta();
	std::string testMouse();
	std::string testKeyboard();
	std::string testGamepad();
	std::string testFacade();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

