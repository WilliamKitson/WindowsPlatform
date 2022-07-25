#include "MouseDefaultCursorTest.h"

MouseDefaultCursorTest::MouseDefaultCursorTest()
{
}

MouseDefaultCursorTest::~MouseDefaultCursorTest()
{
}

std::string MouseDefaultCursorTest::test()
{
	if (success())
	{
		return std::string();
	}

	return "mouse default cursor test failed\n";
}

bool MouseDefaultCursorTest::success()
{
	if (windowsPlatform::Mouse().getCursor().x != 0.0f)
	{
		return false;
	}

	if (windowsPlatform::Mouse().getCursor().y != 0.0f)
	{
		return false;
	}

	return true;
}
