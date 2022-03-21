#pragma once

#include <Windows.h>
#include <string>

#include "FacadeQuitDefaultTest.h"

class FacadeQuitTester
{
public:
	FacadeQuitTester(HINSTANCE, int);
	~FacadeQuitTester();

	std::string test();


private:
	std::string testDefault();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

