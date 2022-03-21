#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeDefaultKeyboardTest
{
public:
	FacadeDefaultKeyboardTest(HINSTANCE, int);
	~FacadeDefaultKeyboardTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

