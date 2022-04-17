#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

class FacadeMinimiseResetTest
{
public:
	FacadeMinimiseResetTest(HINSTANCE, int);
	~FacadeMinimiseResetTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
