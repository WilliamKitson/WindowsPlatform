#include "WindowDefaultQuitTest.h"

WindowDefaultQuitTest::WindowDefaultQuitTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowDefaultQuitTest::~WindowDefaultQuitTest()
{
}

std::string WindowDefaultQuitTest::test()
{
	if (WindowsPlatform::ApplicationWindow(hInstance, nCmdShow, "window default quit test").getQuit() == false)
	{
		return std::string();
	}

	return "window default quit test failed\n";
}
