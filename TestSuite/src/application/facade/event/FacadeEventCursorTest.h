#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "SubordinateImplimentation.h"

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
