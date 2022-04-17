#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Facade.h"
#include "Implimentation.h"

class FacadeWindowTagTest
{
public:
	FacadeWindowTagTest(HINSTANCE, int);
	~FacadeWindowTagTest();

	std::string test();

private:
	std::wstring getWindowTitle(HWND);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::string tag;
};
