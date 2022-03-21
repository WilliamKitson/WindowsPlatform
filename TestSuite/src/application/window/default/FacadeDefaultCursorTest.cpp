#include "FacadeDefaultCursorTest.h"

FacadeDefaultCursorTest::FacadeDefaultCursorTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeDefaultCursorTest::~FacadeDefaultCursorTest()
{
}

std::string FacadeDefaultCursorTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade default cursor test"
	);

	WindowsPlatform::Vector2 cursor = unit->getCursor();

	delete unit;
	unit = nullptr;

	if (cursor == WindowsPlatform::Vector2())
	{
		return std::string();
	}

	return "facade default cursor test failed\n";
}
