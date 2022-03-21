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
	WindowsPlatform::SubordinateImplimentation unit{
		hInstance,
		nCmdShow,
		"window open post quit test"
	};

	PostMessage(
		unit.getWindow(),
		WM_CLOSE,
		0,
		0
	);

	unit.update();

	if (IsWindow(unit.getWindow()))
	{
		return std::string();
	}

	return "window open post quit test failed\n";
}
