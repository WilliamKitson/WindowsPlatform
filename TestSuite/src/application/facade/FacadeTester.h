#pragma once

#include <Windows.h>
#include <string>

#include "window/FacadeWindowTester.h"
#include "quit/FacadeQuitTester.h"
#include "minimise/FacadeMinimiseTester.h"
#include "default/FacadeDefaultTester.h"
#include "event/FacadeEventTester.h"
#include "FacadeOpenPostQuitTest.h"
#include "FacadeDeltaTest.h"

class FacadeTester
{
public:
	FacadeTester(HINSTANCE, int);
	~FacadeTester();

	std::string test();


private:
	std::string testWindow();
	std::string testQuit();
	std::string testMinimise();
	std::string testDefault();
	std::string testEvent();
	std::string testOpenPostQuit();
	std::string testDelta();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

