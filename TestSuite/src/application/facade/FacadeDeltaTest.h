#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

class FacadeDeltaTest
{
public:
	FacadeDeltaTest(HINSTANCE, int);
	~FacadeDeltaTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
