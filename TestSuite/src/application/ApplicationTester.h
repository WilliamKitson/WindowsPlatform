#pragma once

#include <Windows.h>
#include <string>

#include "delta/DeltaTester.h"
#include "window/WindowTester.h"
#include "mouse/MouseTester.h"
#include "keyboard/KeyboardTester.h"
#include "facade/FacadeTester.h"

class ApplicationTester
{
public:
	ApplicationTester(HINSTANCE, int);
	~ApplicationTester();

	std::string test();

private:
	std::string testDelta();
	std::string testWindow();
	std::string testMouse();
	std::string testKeyboard();
	std::string testFacade();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
