#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeEventKeyboardTest
{
public:
	FacadeEventKeyboardTest(HINSTANCE, int);
	~FacadeEventKeyboardTest();

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

