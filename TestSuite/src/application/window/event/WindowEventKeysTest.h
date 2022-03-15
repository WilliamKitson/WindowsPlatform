#pragma once

#include <Windows.h>
#include <string>

#include "ApplicationWindow.h"

class WindowEventKeysTest
{
public:
	WindowEventKeysTest(HINSTANCE, int);
	~WindowEventKeysTest();

	std::string test();


private:
	void postDown(HWND, WindowsPlatform::WindowsButtons);
	void postUp(HWND, WindowsPlatform::WindowsButtons);
	bool isSysKey(WindowsPlatform::WindowsButtons);
	int getKeyCode(WindowsPlatform::WindowsButtons);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

