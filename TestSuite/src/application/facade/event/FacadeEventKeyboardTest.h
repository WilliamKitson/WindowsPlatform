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
	void postDown(HWND, windowsPlatform::KeyboardKeys);
	void postUp(HWND, windowsPlatform::KeyboardKeys);
	bool isSysKey(windowsPlatform::KeyboardKeys);
	WPARAM getKeyCode(windowsPlatform::KeyboardKeys);


private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};

