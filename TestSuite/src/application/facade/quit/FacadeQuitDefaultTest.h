#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

class FacadeQuitDefaultTest
{
public:
	FacadeQuitDefaultTest(HINSTANCE, int);
	~FacadeQuitDefaultTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
