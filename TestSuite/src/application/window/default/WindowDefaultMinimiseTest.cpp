#include "WindowDefaultMinimiseTest.h"

WindowDefaultMinimiseTest::WindowDefaultMinimiseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowDefaultMinimiseTest::~WindowDefaultMinimiseTest()
{
}

std::string WindowDefaultMinimiseTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance, 
		nCmdShow, 
		"facade default minimise test"
	);

	bool minimise = unit->getMinimise();

	delete unit;
	unit = nullptr;

	if (minimise == false)
	{
		return std::string();
	}

	return "facade default minimise test failed\n";
}
