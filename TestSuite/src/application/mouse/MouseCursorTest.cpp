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

	if (unit.getCursor() == cursor)
	{
		return std::string();
	}

	return "mouse cursor test failed\n";
}
