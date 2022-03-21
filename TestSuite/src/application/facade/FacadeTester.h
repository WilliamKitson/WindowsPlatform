#pragma once

#include <Windows.h>
#include <string>

#include "default/FacadeDefaultTester.h"
#include "tag/FacadeTagTester.h"
#include "resolution/FacadeResolutionTester.h"
#include "style/FacadeStyleTester.h"
#include "event/FacadeEventTester.h"
#include "FacadeDestroyedTest.h"
#include "FacadeOpenPostQuitTest.h"

class FacadeTester
{
public:
	FacadeTester(HINSTANCE, int);
	~FacadeTester();

	std::string test();


private:
	std::string testDefault();
	std::string testTag();
	std::string testResolution();
	std::string testStyle();
	std::string testEvent();
	std::string testDestroyed();
	std::string testOpenPostQuit();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

