#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"
#include "Vector2.h"

class WindowResolutionSetTest
{
public:
	WindowResolutionSetTest(HINSTANCE, int);
	~WindowResolutionSetTest();

	std::string test();


private:
	HRESULT initialiseWindowClass();
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	WindowsPlatform::Vector2 windowResolution(HWND);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	WNDCLASSEX windowClass;
	WindowsPlatform::Vector2 resolution;
};

