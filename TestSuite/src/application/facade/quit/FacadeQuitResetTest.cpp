#include "FacadeQuitResetTest.h"

FacadeQuitResetTest::FacadeQuitResetTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeQuitResetTest::~FacadeQuitResetTest()
{
}

std::string FacadeQuitResetTest::test()
{
	windowsPlatform::Facade* unit = new windowsPlatform::Implimentation(
		hInstance,
		nCmdShow,
		"facade quit reset test"
	);

	PostMessage(
		unit->getWindow(),
		WM_CLOSE,
		0,
		0
	);

	unit->update();
	unit->update();
	bool quit = unit->getQuit();

	delete unit;
	unit = nullptr;

	if (quit == false)
	{
		return std::string();
	}

	return "facade quit reset test failed\n";
}
