#include "MouseStateYdragTest.h"

MouseStateYdragTest::MouseStateYdragTest()
{
}

MouseStateYdragTest::~MouseStateYdragTest()
{
}

std::string MouseStateYdragTest::test()
{
	WindowsPlatform::MouseState unit{
		0,
		0,
		0,
		1
	};

	if ((unit == WindowsPlatform::MouseState()) == false)
	{
		return std::string();
	}

	return "mouse state ydrag test failed\n";
}
