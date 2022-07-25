#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

class FacadeEventCursorTest
{
public:
	FacadeEventCursorTest(HINSTANCE, int);
	~FacadeEventCursorTest();

	std::string test();

private:
	bool success(windowsPlatform::Vector2);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	windowsPlatform::Facade* unit;
	int itterations;
	int successes;
};
