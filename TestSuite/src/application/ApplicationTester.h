#pragma once

#include <Windows.h>
#include <string>

#include "window/WindowTester.h"
#include "delta/DeltaTester.h"
#include "gamepad/GamepadTester.h"
#include "facade/FacadeTester.h"

class ApplicationTester
{
public:
	ApplicationTester(HINSTANCE, int);
	~ApplicationTester();

	std::string test();


private:
	std::string testWindow();
	std::string testDelta();
	std::string testGamepad();
	std::string testFacade();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

