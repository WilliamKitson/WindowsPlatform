#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Window.h"

class WindowStyleBorderlessTest
{
public:
	WindowStyleBorderlessTest(HINSTANCE, int);
	~WindowStyleBorderlessTest();

	std::string test();

private:
	HRESULT initialiseWindowClass();
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	WNDCLASSEX windowClass;
};
