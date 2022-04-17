#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

class FacadeOpenPostQuitTest
{
public:
	FacadeOpenPostQuitTest(HINSTANCE, int);
	~FacadeOpenPostQuitTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
