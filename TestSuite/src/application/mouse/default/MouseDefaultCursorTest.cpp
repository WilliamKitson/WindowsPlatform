#include "MouseDefaultCursorTest.h"

MouseDefaultCursorTest::MouseDefaultCursorTest()
{
}

MouseDefaultCursorTest::~MouseDefaultCursorTest()
{
}

std::string MouseDefaultCursorTest::test()
{
	if (windowsPlatform::Mouse().getCursor() == windowsPlatform::Vector2())
	{
		return std::string();
	}

	return "mouse default cursor test failed\n";
}
