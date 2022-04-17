#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "SubordinateImplimentation.h"

class FacadeEventMouseTest
{
public:
	FacadeEventMouseTest(HINSTANCE, int);
	~FacadeEventMouseTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
	int successes;
};
