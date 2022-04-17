#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

class FacadeMinimiseEventTest
{
public:
	FacadeMinimiseEventTest(HINSTANCE, int);
	~FacadeMinimiseEventTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
