#pragma once

#include <Windows.h>
#include <string>

#include "window/WindowTester.h"
#include "delta/DeltaTester.h"

class ApplicationTester
{
public:
	ApplicationTester(HINSTANCE, int);
	~ApplicationTester();

	std::string test();


private:
	std::string testWindow();
	std::string testDelta();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

