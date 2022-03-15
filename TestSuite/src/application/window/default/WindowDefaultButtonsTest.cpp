#include "WindowDefaultButtonsTest.h"

WindowDefaultButtonsTest::WindowDefaultButtonsTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, successes{ 0 }
{
}

WindowDefaultButtonsTest::~WindowDefaultButtonsTest()
{
}

std::string WindowDefaultButtonsTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		""
	};

	for (int i{ 0 }; i < (int)WindowsPlatform::WindowsButtons::windowsButtonsSize; i++)
	{
		successes += unit.getButton((WindowsPlatform::WindowsButtons)i) == false;
	}

	if (successes == (int)WindowsPlatform::WindowsButtons::windowsButtonsSize)
	{
		return std::string();
	}

	return "window default buttons test failed\n";
}
