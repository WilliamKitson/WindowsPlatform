#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "ApplicationWindow.h"
#include "Vector2.h"

class WindowResolutionMinimumTest
{
public:
	WindowResolutionMinimumTest(HINSTANCE, int);
	~WindowResolutionMinimumTest();

	std::string test(); 

private:
	HRESULT initialiseWindowClass();
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	windowsPlatform::Vector2 windowResolution(HWND);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	WNDCLASSEX windowClass;
};
