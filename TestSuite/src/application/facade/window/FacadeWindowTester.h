#pragma once

#include <Windows.h>
#include <string>

#include "FacadeWindowParameterTest.h"
#include "FacadeWindowQuitTest.h"
#include "FacadeWindowMinimiseTest.h"
#include "FacadeWindowCursorTest.h"
#include "FacadeWindowDragTest.h"
#include "FacadeWindowButtonsTest.h"
#include "FacadeWindowKeysTest.h"
#include "FacadeWindowTagTest.h"
#include "FacadeWindowWidthTest.h"
#include "FacadeWindowHeightTest.h"

class FacadeWindowTester
{
public:
	FacadeWindowTester(HINSTANCE, int);
	~FacadeWindowTester();

	std::string test();


private:
	std::string testParameter();
	std::string testQuit();
	std::string testMinimise();
	std::string testCursor();
	std::string testDrag();
	std::string testButtons();
	std::string testKeys();
	std::string testTag();
	std::string testWidth();
	std::string testHeight();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

