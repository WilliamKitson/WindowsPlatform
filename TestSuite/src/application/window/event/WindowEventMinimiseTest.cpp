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
	ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window event minimise test: MINIMISE TO CONTINUE"
	};

	while (unit.getMinimise() == false)
	{
		unit.update();
	}

	unit.update();

	if (unit.getMinimise() == false)
	{
		return std::string();
	}

	return "window event minimise test failed\n";
}
