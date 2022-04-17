#include "FacadeMinimiseResetTest.h"

FacadeMinimiseResetTest::FacadeMinimiseResetTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeMinimiseResetTest::~FacadeMinimiseResetTest()
{
}

std::string FacadeMinimiseResetTest::test()
{
	windowsPlatform::Facade* unit = new windowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade minimise reset test"
	);

	PostMessage(
		unit->getWindow(),
		WM_SIZE,
		SIZE_MINIMIZED,
		0
	);

	unit->update();
	unit->update();
	bool minimise = unit->getMinimise();

	delete unit;
	unit = nullptr;

	if (minimise == false)
	{
		return std::string();
	}

	return "facade minimise reset test failed\n";
}
