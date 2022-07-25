#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Window.h"
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
	bool success(windowsPlatform::Vector2);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	WNDCLASSEX windowClass;
};
