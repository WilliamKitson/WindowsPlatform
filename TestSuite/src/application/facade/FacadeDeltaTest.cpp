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
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade delta test"
	);

	Sleep(500);
	unit->update();

	float elapsed = unit->getDelta();

	delete unit;
	unit = nullptr;

	if (elapsed > 0.5f)
	{
		return std::string();
	}

	return "facade delta test failed\n";
}
