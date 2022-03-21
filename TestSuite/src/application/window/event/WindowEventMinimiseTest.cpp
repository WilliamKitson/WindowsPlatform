#include "WindowEventMinimiseTest.h"

WindowEventMinimiseTest::WindowEventMinimiseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventMinimiseTest::~WindowEventMinimiseTest()
{
}

std::string WindowEventMinimiseTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade event minimise test"
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

	return "facade event minimise test failed\n";
}
