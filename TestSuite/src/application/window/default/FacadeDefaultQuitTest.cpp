#include "FacadeDefaultQuitTest.h"

FacadeDefaultQuitTest::FacadeDefaultQuitTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeDefaultQuitTest::~FacadeDefaultQuitTest()
{
}

std::string FacadeDefaultQuitTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::ApplicationWindow(
		hInstance, 
		nCmdShow, 
		"facade default quit test"
	);

	bool quit = unit->getQuit();

	delete unit;
	unit = nullptr;

	if (quit == false)
	{
		return std::string();
	}

	return "facade default quit test failed\n";
}
