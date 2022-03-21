#include "WindowDefaultMouseTest.h"

WindowDefaultMouseTest::WindowDefaultMouseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, successes{ 0 }
{
}

WindowDefaultMouseTest::~WindowDefaultMouseTest()
{
}

std::string WindowDefaultMouseTest::test()
{
	WindowsPlatform::SubordinateImplimentation unit{
		hInstance,
		nCmdShow,
		"window default mouse test"
	};

	for (int i{ 0 }; i < (int)WindowsPlatform::MouseButtons::size; i++)
	{
		successes += unit.getMouse((WindowsPlatform::MouseButtons)i) == false;
	}

	if (successes == (int)WindowsPlatform::MouseButtons::size)
	{
		return std::string();
	}

	return "window default mouse test failed\n";
}
