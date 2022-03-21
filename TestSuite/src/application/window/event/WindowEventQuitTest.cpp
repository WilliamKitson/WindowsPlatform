#include "WindowEventQuitTest.h"

WindowEventQuitTest::WindowEventQuitTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventQuitTest::~WindowEventQuitTest()
{
}

std::string WindowEventQuitTest::test()
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
