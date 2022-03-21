#pragma once

#include <Windows.h>
#include <string>
#include <vector>
#include <codecvt>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeTagParameterTest
{
public:
	FacadeTagParameterTest(HINSTANCE, int);
	~FacadeTagParameterTest();

	std::string test();


private:
	std::wstring getWindowTitle(HWND);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const std::string tag;
};

