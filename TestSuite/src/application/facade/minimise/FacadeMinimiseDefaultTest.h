#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

class FacadeDefaultMinimiseTest
{
public:
	FacadeDefaultMinimiseTest(HINSTANCE, int);
	~FacadeDefaultMinimiseTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
