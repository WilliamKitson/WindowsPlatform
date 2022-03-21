#pragma once

#include <Windows.h>
#include <string>

#include "FacadeMinimiseDefaultTest.h"

class FacadeMinimiseTester
{
public:
	FacadeMinimiseTester(HINSTANCE, int);
	~FacadeMinimiseTester();

	std::string test();


private:
	std::string testDefault();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

