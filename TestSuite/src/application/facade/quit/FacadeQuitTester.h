#pragma once

#include <Windows.h>
#include <string>

#include "FacadeQuitDefaultTest.h"
#include "FacadeQuitEventTest.h"
#include "FacadeQuitResetTest.h"

class FacadeQuitTester
{
public:
	FacadeQuitTester(HINSTANCE, int);
	~FacadeQuitTester();

	std::string test();

private:
	std::string testDefault();
	std::string testEvent();
	std::string testReset();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
