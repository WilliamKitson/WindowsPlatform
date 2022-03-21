#pragma once

#include <Windows.h>
#include <string>

#include "quit/FacadeQuitTester.h"
#include "minimise/FacadeMinimiseTester.h"
#include "default/FacadeDefaultTester.h"
#include "tag/FacadeTagTester.h"
#include "resolution/FacadeResolutionTester.h"
#include "style/FacadeStyleTester.h"
#include "event/FacadeEventTester.h"
#include "FacadeDestroyedTest.h"
#include "FacadeOpenPostQuitTest.h"
#include "FacadeDeltaTest.h"

class FacadeTester
{
public:
	FacadeTester(HINSTANCE, int);
	~FacadeTester();

	std::string test();


private:
	std::string testQuit();
	std::string testMinimise();
	std::string testDefault();
	std::string testTag();
	std::string testResolution();
	std::string testStyle();
	std::string testEvent();
	std::string testDestroyed();
	std::string testOpenPostQuit();
	std::string testDelta();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

