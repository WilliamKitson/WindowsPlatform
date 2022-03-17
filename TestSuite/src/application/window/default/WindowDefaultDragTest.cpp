#include "WindowDefaultDragTest.h"

WindowDefaultDragTest::WindowDefaultDragTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowDefaultDragTest::~WindowDefaultDragTest()
{
}

std::string WindowDefaultDragTest::test()
{
	if (WindowsPlatform::ApplicationWindow(hInstance, nCmdShow, "window default drag test").getDrag() == WindowsPlatform::Vector2())
	{
		return std::string();
	}

	return "window default drag test failed\n";
}
