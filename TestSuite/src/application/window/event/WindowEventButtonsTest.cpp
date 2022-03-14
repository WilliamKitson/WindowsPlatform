#include "WindowEventButtonsTest.h"

WindowEventButtonsTest::WindowEventButtonsTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowEventButtonsTest::~WindowEventButtonsTest()
{
}

std::string WindowEventButtonsTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window event buttons test"
	};

	for (unsigned int i{ 0 }; i < (unsigned int)WindowsButtons::windowsButtonsSize; i++)
	{
		if (unit.getButton((WindowsButtons)i) == true)
		{
			return "window event buttons test failed\n";
		}
	}
	
	return std::string();
}
