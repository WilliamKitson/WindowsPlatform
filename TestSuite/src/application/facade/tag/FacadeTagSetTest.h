#pragma once

#include <Windows.h>
#include <string>
#include <vector>
#include <codecvt>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeTagSetTest
{
public:
	FacadeTagSetTest(HINSTANCE, int);
	~FacadeTagSetTest();

	std::string test();


private:
	std::wstring getWindowTitle(HWND);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const std::string tag;
};

