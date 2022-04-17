#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

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
