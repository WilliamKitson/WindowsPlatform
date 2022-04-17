#include "FacadeMinimiseDefaultTest.h"

FacadeDefaultMinimiseTest::FacadeDefaultMinimiseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeDefaultMinimiseTest::~FacadeDefaultMinimiseTest()
{
}

std::string FacadeDefaultMinimiseTest::test()
{
	windowsPlatform::Facade* unit = new windowsPlatform::SubordinateImplimentation(
		hInstance, 
		nCmdShow, 
		"facade minimise defualt test"
	);

	bool minimise = unit->getMinimise();

	delete unit;
	unit = nullptr;

	if (minimise == false)
	{
		return std::string();
	}

	return "facade minimise default test failed\n";
}
