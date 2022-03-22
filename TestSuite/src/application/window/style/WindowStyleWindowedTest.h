#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "ApplicationWindow.h"

class WindowStyleWindowedTest
{
public:
	WindowStyleWindowedTest(HINSTANCE, int);
	~WindowStyleWindowedTest();

	std::string test();


private:
	HRESULT initialiseWindowClass();
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	WNDCLASSEX windowClass;
};

