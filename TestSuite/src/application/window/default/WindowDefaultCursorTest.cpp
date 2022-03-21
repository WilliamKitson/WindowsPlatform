#include "WindowDefaultCursorTest.h"

WindowDefaultCursorTest::WindowDefaultCursorTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowDefaultCursorTest::~WindowDefaultCursorTest()
{
}

std::string WindowDefaultCursorTest::test()
{
	if (WindowsPlatform::SubordinateImplimentation(hInstance, nCmdShow, "window default cursor test").getCursor() == WindowsPlatform::Vector2())
	{
		return std::string();
	}

	return "windows default cursor test failed\n";
}
