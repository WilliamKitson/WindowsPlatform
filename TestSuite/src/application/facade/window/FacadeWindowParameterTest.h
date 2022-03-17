#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowParameterTest
{
public:
	FacadeWindowParameterTest(HINSTANCE, int);
	~FacadeWindowParameterTest();

	std::string test();


private:
	std::wstring getWindowTitle(HWND);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::string tag;
};

