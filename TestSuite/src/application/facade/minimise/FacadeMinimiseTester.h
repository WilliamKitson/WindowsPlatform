#pragma once

#include <Windows.h>
#include <string>

#include "FacadeMinimiseDefaultTest.h"
#include "FacadeMinimiseEventTest.h"
#include "FacadeMinimiseResetTest.h"

class FacadeMinimiseTester
{
public:
	FacadeMinimiseTester(HINSTANCE, int);
	~FacadeMinimiseTester();

	std::string test();

private:
	std::string testDefault();
	std::string testEvent();
	std::string testReset();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
