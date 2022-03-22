#pragma once

#include <Windows.h>
#include <string>
#include <vector>
#include <codecvt>

#include "ApplicationWindow.h"

class WindowTagSetTest
{
public:
	WindowTagSetTest(HINSTANCE, int);
	~WindowTagSetTest();

	std::string test();


private:
	HRESULT initialiseWindowClass();
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	std::wstring getWindowTitle(HWND);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	WNDCLASSEX windowClass;
	std::string tag;
};

