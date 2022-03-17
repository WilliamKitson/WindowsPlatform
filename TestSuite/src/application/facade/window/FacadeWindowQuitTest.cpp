#include "FacadeWindowQuitTest.h"

FacadeWindowQuitTest::FacadeWindowQuitTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeWindowQuitTest::~FacadeWindowQuitTest()
{
}

std::string FacadeWindowQuitTest::test()
{
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window quit test"
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

	if (quit)
	{
		return std::string();
	}

	return "facade window quit test failed\n";
}
