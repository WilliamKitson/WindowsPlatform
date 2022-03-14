#include "WindowResolutionSetWidthTest.h"

WindowsResolutionSetWidthTest::WindowsResolutionSetWidthTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, width{ 1000 }
{
}

WindowsResolutionSetWidthTest::~WindowsResolutionSetWidthTest()
{
}

std::string WindowsResolutionSetWidthTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window resolution set width test"
	};

	WindowsPlatform::Resolution set{
		width,
		0
	};

	unit.setResolution(set);

	RECT resolution;

	GetClientRect(
		unit.getWindow(),
		&resolution
	);

	if ((resolution.right - resolution.left) == width)
	{
		return std::string();
	}

	return "windows resolution set width test failed\n";
}
