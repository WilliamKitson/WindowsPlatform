#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Window.h"
#include "Vector2.h"

class WindowResolutionDefaultTest
{
public:
	WindowResolutionDefaultTest(HINSTANCE, int);
	~WindowResolutionDefaultTest();

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
