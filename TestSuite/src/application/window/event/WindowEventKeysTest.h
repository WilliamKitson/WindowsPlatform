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
	void postDown(HWND, WindowsPlatform::KeyboardKeys);
	void postUp(HWND, WindowsPlatform::KeyboardKeys);
	bool isSysKey(WindowsPlatform::KeyboardKeys);
	WPARAM getKeyCode(WindowsPlatform::KeyboardKeys);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

