#include "MouseDefaultCursorTest.h"

MouseDefaultCursorTest::MouseDefaultCursorTest()
{
}

MouseDefaultCursorTest::~MouseDefaultCursorTest()
{
}

std::string MouseDefaultCursorTest::test()
{
	bool successes = true;

	if (windowsPlatform::Mouse().getCursor().x != 0.0f)
	{
		successes = false;
	}

	if (windowsPlatform::Mouse().getCursor().y != 0.0f)
	{
		successes = false;
	}

	if (successes)
	{
		return std::string();
	}

	return "mouse default cursor test failed\n";
}
