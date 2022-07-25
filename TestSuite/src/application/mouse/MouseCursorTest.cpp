#include "MouseCursorTest.h"

MouseCursorTest::MouseCursorTest()
	: cursor{ 1.0f, 2.0f }
{
}

MouseCursorTest::~MouseCursorTest()
{
}

std::string MouseCursorTest::test()
{
	windowsPlatform::Mouse unit;
	unit.move(MAKELPARAM(cursor.x, cursor.y));

	if (success(unit.getCursor()))
	{
		return std::string();
	}

	return "mouse cursor test failed\n";
}

bool MouseCursorTest::success(windowsPlatform::Vector2 input)
{
	if (input.x != cursor.x)
	{
		return false;
	}

	if (input.y != cursor.y)
	{
		return false;
	}

	return true;
}
