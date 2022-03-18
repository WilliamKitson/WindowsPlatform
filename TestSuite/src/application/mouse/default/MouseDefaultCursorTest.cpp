#include "MouseDefaultCursorTest.h"

MouseDefaultCursorTest::MouseDefaultCursorTest()
{
}

MouseDefaultCursorTest::~MouseDefaultCursorTest()
{
}

std::string MouseDefaultCursorTest::test()
{
	if (WindowsPlatform::Mouse().getCursor() == WindowsPlatform::Vector2())
	{
		return std::string();
	}

	return "mouse default cursor test failed\n";
}
