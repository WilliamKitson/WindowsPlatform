#include "WindowOpenPostQuitTest.h"

WindowOpenPostQuitTest::WindowOpenPostQuitTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowOpenPostQuitTest::~WindowOpenPostQuitTest()
{
}

std::string WindowOpenPostQuitTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade open post quit test"
	);

	PostMessage(
		unit->getWindow(),
		WM_CLOSE,
		0,
		0
	);

	unit->update();
	bool open = IsWindow(unit->getWindow());

	delete unit;
	unit = nullptr;

	if (open)
	{
		return std::string();
	}

	return "facade open post quit test failed\n";
}
