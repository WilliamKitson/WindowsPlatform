#include "FacadeEventQuitTest.h"

FacadeEventQuitTest::FacadeEventQuitTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeEventQuitTest::~FacadeEventQuitTest()
{
}

std::string FacadeEventQuitTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade event quit test"
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

	return "facade event quit test failed\n";
}
