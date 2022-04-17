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
	void postDown(HWND, windowsPlatform::Keys);
	void postUp(HWND, windowsPlatform::Keys);
	bool isSysKey(windowsPlatform::Keys);
	WPARAM getKeyCode(windowsPlatform::Keys);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};
