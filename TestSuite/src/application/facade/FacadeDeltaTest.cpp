#include "FacadeDeltaTest.h"

FacadeDeltaTest::FacadeDeltaTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeDeltaTest::~FacadeDeltaTest()
{
}

std::string FacadeDeltaTest::test()
{
	windowsPlatform::Facade* unit = new windowsPlatform::Implimentation(
		hInstance,
		nCmdShow,
		"facade delta test"
	);

	Sleep(500);
	unit->update();

	float delta = unit->getDelta();

	delete unit;
	unit = nullptr;

	if (delta > 0.5f)
	{
		return std::string();
	}

	return "facade delta test failed\n";
}
