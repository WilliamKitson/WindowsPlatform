#pragma once

#include <Windows.h>
#include <string>

#include "FacadeWindowQuitTest.h"
#include "FacadeWindowMinimiseTest.h"
#include "FacadeWindowCursorTest.h"
#include "FacadeWindowButtonsTest.h"
#include "FacadeWindowKeysTest.h"

class FacadeWindowTester
{
public:
	FacadeWindowTester(HINSTANCE, int);
	~FacadeWindowTester();

	std::string test();


private:
	std::string testQuit();
	std::string testMinimise();
	std::string testCursor();
	std::string testButtons();
	std::string testKeys();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

