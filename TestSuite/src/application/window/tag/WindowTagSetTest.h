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
	std::wstring getWindowTitle(HWND);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	const std::string tag;
};

