#include "FacadeOpenPostQuitTest.h"

FacadeOpenPostQuitTest::FacadeOpenPostQuitTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeOpenPostQuitTest::~FacadeOpenPostQuitTest()
{
}

std::string FacadeOpenPostQuitTest::test()
{
	windowsPlatform::Facade* unit = new windowsPlatform::Implimentation(
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
