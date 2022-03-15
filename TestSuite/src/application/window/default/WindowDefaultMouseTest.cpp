#include "WindowDefaultMouseTest.h"

WindowDefaultMouseTest::WindowDefaultMouseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowDefaultMouseTest::~WindowDefaultMouseTest()
{
}

std::string WindowDefaultMouseTest::test()
{
	if (WindowsPlatform::ApplicationWindow(hInstance, nCmdShow, "").getMouse() == WindowsPlatform::MouseState())
	{
		return std::string();
	}

	return "window default mouse test failed\n";
}
