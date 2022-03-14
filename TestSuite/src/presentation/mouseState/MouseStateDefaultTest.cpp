#include "MouseStateDefaultTest.h"

MouseStateDefaultTest::MouseStateDefaultTest()
{
}

MouseStateDefaultTest::~MouseStateDefaultTest()
{
}

std::string MouseStateDefaultTest::test()
{
	MouseState unit{
		0,
		0,
		0.0f,
		0.0f
	};

	if (unit == MouseState())
	{
		return std::string();
	}

	return "mouse state default test failed\n";
}
