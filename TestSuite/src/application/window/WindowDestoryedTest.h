#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "ApplicationWindow.h"

class WindowDestroyedTest
{
public:
	WindowDestroyedTest(HINSTANCE, int);
	~WindowDestroyedTest();

	std::string test();

private:
	HRESULT initialiseWindowClass();
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	WNDCLASSEX windowClass;
};
