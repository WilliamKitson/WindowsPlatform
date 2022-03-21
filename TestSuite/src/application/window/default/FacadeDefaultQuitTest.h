#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "ApplicationWindow.h"

class FacadeDefaultQuitTest
{
public:
	FacadeDefaultQuitTest(HINSTANCE, int);
	~FacadeDefaultQuitTest();

	std::string test();


private:
	HINSTANCE hInstance;
	int nCmdShow;
};

