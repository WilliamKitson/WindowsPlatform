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
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade default mouse test"
	);

	for (int i{ 0 }; i < (int)WindowsPlatform::MouseButtons::size; i++)
	{
		successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == false;
	}

	delete unit;
	unit = nullptr;

	if (successes == (int)WindowsPlatform::MouseButtons::size)
	{
		return std::string();
	}

	return "facade default mouse test failed\n";
}
