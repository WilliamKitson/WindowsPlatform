#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Window.h"

class WindowTagInitialiseTest
{
public:
	WindowTagInitialiseTest(HINSTANCE, int);
	~WindowTagInitialiseTest();

	std::string test();

private:
	HRESULT initialiseWindowClass();
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	std::wstring getWindowTitle(HWND);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	WNDCLASSEX windowClass;
	std::wstring tag;
};
