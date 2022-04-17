#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Facade.h"
#include "Implimentation.h"

class FacadeWindowBorderlessTest
{
public:
	FacadeWindowBorderlessTest(HINSTANCE, int);
	~FacadeWindowBorderlessTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
