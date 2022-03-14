#pragma once

#include <Windows.h>
#include <string>

#include "WindowTagParameterTest.h"
#include "WindowTagSetTest.h"

class WindowTagTester
{
public:
	WindowTagTester(HINSTANCE, int);
	~WindowTagTester();

	std::string test();


private:
	std::string testParameter();
	std::string testSet();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

