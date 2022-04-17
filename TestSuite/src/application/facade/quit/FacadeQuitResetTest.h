#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

class FacadeQuitResetTest
{
public:
	FacadeQuitResetTest(HINSTANCE, int);
	~FacadeQuitResetTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
