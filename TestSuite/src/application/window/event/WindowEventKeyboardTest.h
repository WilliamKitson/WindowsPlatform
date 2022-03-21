#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateImplimentation.h"

class WindowEventKeyboardTest
{
public:
	WindowEventKeyboardTest(HINSTANCE, int);
	~WindowEventKeyboardTest();

	std::string test();


private:
	void postDown(HWND, WindowsPlatform::KeyboardKeys);
	void postUp(HWND, WindowsPlatform::KeyboardKeys);
	bool isSysKey(WindowsPlatform::KeyboardKeys);
	WPARAM getKeyCode(WindowsPlatform::KeyboardKeys);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

