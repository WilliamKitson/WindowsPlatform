#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Facade.h"
#include "Implimentation.h"

class FacadeWindowWindowedTest
{
public:
	FacadeWindowWindowedTest(HINSTANCE, int);
	~FacadeWindowWindowedTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
