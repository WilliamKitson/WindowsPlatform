#include "MouseStateDefaultTest.h"

MouseStateDefaultTest::MouseStateDefaultTest()
{
}

MouseStateDefaultTest::~MouseStateDefaultTest()
{
}

std::string MouseStateDefaultTest::test()
{
	WindowsPlatform::MouseState unit{
		0,
		0,
		0,
		0
	};

	if (unit == WindowsPlatform::MouseState())
	{
		return std::string();
	}

	return "mouse state default test failed\n";
}
