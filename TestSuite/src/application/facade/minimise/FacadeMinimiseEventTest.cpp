#include "FacadeMinimiseEventTest.h"

FacadeMinimiseEventTest::FacadeMinimiseEventTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeMinimiseEventTest::~FacadeMinimiseEventTest()
{
}

std::string FacadeMinimiseEventTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade minimise event test"
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

	if (minimise == true)
	{
		return std::string();
	}

	return "facade minimise event test failed\n";
}
