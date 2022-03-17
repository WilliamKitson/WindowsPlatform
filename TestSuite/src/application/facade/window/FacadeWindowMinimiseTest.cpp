#include "FacadeWindowMinimiseTest.h"

FacadeWindowMinimiseTest::FacadeWindowMinimiseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeWindowMinimiseTest::~FacadeWindowMinimiseTest()
{
}

std::string FacadeWindowMinimiseTest::test()
{
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window minimise test"
	);

	PostMessage(
		unit->getWindow(),
		WM_SIZE,
		SIZE_MINIMIZED,
		0
	);

	unit->update();
	bool minimise = unit->getMinimise();

	delete unit;
	unit = nullptr;

	if (minimise)
	{
		return std::string();
	}

	return "facade window minimise test failed\n";
}
