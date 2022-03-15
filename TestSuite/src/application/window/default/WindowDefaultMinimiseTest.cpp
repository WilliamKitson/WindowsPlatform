#include "WindowDefaultMinimiseTest.h"

WindowDefaultMinimiseTest::WindowDefaultMinimiseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowDefaultMinimiseTest::~WindowDefaultMinimiseTest()
{
}

std::string WindowDefaultMinimiseTest::test()
{
	if (WindowsPlatform::ApplicationWindow(hInstance, nCmdShow, "window default minimise test").getMinimise() == false)
	{
		return std::string();
	}

	return "window default minimise test failed\n";
}
