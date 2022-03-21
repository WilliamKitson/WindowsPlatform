#include "WindowDefaultKeyboardTest.h"

WindowDefaultKeyboardTest::WindowDefaultKeyboardTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, successes{ 0 }
{
}

WindowDefaultKeyboardTest::~WindowDefaultKeyboardTest()
{
}

std::string WindowDefaultKeyboardTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window default keyboard test"
	};

	for (int i{ 0 }; i < (int)WindowsPlatform::KeyboardKeys::size; i++)
	{
		successes += unit.getKeyboard((WindowsPlatform::KeyboardKeys)i) == false;
	}

	if (successes == (int)WindowsPlatform::KeyboardKeys::size)
	{
		return std::string();
	}

	return "window default keyboard test failed\n";
}
