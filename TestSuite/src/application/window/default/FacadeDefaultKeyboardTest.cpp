#include "FacadeDefaultKeyboardTest.h"

FacadeDefaultKeyboardTest::FacadeDefaultKeyboardTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, successes{ 0 }
{
}

FacadeDefaultKeyboardTest::~FacadeDefaultKeyboardTest()
{
}

std::string FacadeDefaultKeyboardTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade default keyboard test"
	);

	for (int i{ 0 }; i < (int)WindowsPlatform::KeyboardKeys::size; i++)
	{
		successes += unit->getKeyboard((WindowsPlatform::KeyboardKeys)i) == false;
	}

	delete unit;
	unit = nullptr;

	if (successes == (int)WindowsPlatform::KeyboardKeys::size)
	{
		return std::string();
	}

	return "facade default keyboard test failed\n";
}
