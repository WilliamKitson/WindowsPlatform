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
	HINSTANCE hInstance;
	int nCmdShow;
	int itterations;
	int successes;
};
