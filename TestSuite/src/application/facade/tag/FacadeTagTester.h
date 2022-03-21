#pragma once

#include <Windows.h>
#include <string>

#include "FacadeTagParameterTest.h"
#include "FacadeTagSetTest.h"

class FacadeTagTester
{
public:
	FacadeTagTester(HINSTANCE, int);
	~FacadeTagTester();

	std::string test();


private:
	std::string testParameter();
	std::string testSet();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

