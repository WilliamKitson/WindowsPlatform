#pragma once

#include <Windows.h>
#include <string>

#include "Facade.h"
#include "Implimentation.h"

class FacadeEventDragTest
{
public:
	FacadeEventDragTest(HINSTANCE, int);
	~FacadeEventDragTest();

	std::string test();

private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::string tagPrefix;
};
