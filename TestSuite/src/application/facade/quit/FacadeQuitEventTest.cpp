#include "FacadeQuitEventTest.h"

FacadeQuitEventTest::FacadeQuitEventTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeQuitEventTest::~FacadeQuitEventTest()
{
}

std::string FacadeQuitEventTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade quit event test"
	);

	PostMessage(
		unit->getWindow(),
		WM_CLOSE,
		0,
		0
	);

	unit->update();
	bool quit = unit->getQuit();

	delete unit;
	unit = nullptr;

	if (quit == true)
	{
		return std::string();
	}

	return "facade quit event test failed\n";
}
