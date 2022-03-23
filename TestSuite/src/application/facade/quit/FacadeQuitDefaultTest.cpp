#include "FacadeQuitDefaultTest.h"

FacadeQuitDefaultTest::FacadeQuitDefaultTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeQuitDefaultTest::~FacadeQuitDefaultTest()
{
}

std::string FacadeQuitDefaultTest::test()
{
	windowsPlatform::SubordianteFacade* unit = new windowsPlatform::SubordinateImplimentation(
		hInstance, 
		nCmdShow, 
		"facade quit default test"
	);

	bool quit = unit->getQuit();

	delete unit;
	unit = nullptr;

	if (quit == false)
	{
		return std::string();
	}

	return "facade quit default test failed\n";
}
