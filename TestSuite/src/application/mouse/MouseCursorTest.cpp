#include "MouseCursorTest.h"

MouseCursorTest::MouseCursorTest()
{
}

MouseCursorTest::~MouseCursorTest()
{
}

std::string MouseCursorTest::test()
{
	windowsPlatform::Vector2 cursor{
		1.0f,
		2.0f
	};

	windowsPlatform::Mouse unit;
	unit.move(MAKELPARAM(cursor.x, cursor.y));

	bool successes = true;

	if (unit.getCursor().x != cursor.x)
	{
		successes = false;
	}

	if (unit.getCursor().y != cursor.y)
	{
		successes = false;
	}

	if (successes)
	{
		return std::string();
	}

	return "mouse cursor test failed\n";
}
