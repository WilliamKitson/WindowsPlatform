#include "MouseCursorTest.h"

MouseCursorTest::MouseCursorTest()
{
}

MouseCursorTest::~MouseCursorTest()
{
}

std::string MouseCursorTest::test()
{
	WindowsPlatform::Vector2 cursor{
		1.0f,
		2.0f
	};

	WindowsPlatform::Mouse unit;
	unit.move(MAKELPARAM(cursor.x, cursor.y));

	if (unit.getCursor() == cursor)
	{
		return std::string();
	}

	return "mouse cursor test failed\n";
}
