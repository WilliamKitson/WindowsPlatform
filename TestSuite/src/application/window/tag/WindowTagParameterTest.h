#pragma once

#include <Windows.h>
#include <string>
#include <vector>
#include <codecvt>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class WindowTagParameterTest
{
public:
	WindowTagParameterTest(HINSTANCE, int);
	~WindowTagParameterTest();

	std::string test();


private:
	std::wstring getWindowTitle(HWND);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const std::string tag;
};

