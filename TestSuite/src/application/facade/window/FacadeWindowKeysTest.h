#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "SubordinateImplimentation.h"

class FacadeWindowKeysTest
{
public:
	FacadeWindowKeysTest(HINSTANCE, int);
	~FacadeWindowKeysTest();

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

