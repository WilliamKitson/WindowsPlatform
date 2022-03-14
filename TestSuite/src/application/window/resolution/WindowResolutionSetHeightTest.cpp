#include "WindowResolutionSetHeightTest.h"

WindowResolutionSetHeightTest::WindowResolutionSetHeightTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, height{ 1000 }
{
}

WindowResolutionSetHeightTest::~WindowResolutionSetHeightTest()
{
}

std::string WindowResolutionSetHeightTest::test()
{
	ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window resolution set height test"
	};

	unit.setResolution(0, height);

	RECT resolution;

	GetClientRect(
		unit.getWindow(),
		&resolution
	);

	if ((resolution.bottom - resolution.top) == height)
	{
		return std::string();
	}

	return "windows resolution set height test failed\n";
}
