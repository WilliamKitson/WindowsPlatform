#include "MouseStateXdragTest.h"

MouseStateXdragTest::MouseStateXdragTest()
{
}

MouseStateXdragTest::~MouseStateXdragTest()
{
}

std::string MouseStateXdragTest::test()
{
	WindowsPlatform::MouseState unit{
		0,
		0,
		1,
		0
	};

	if ((unit == WindowsPlatform::MouseState()) == false)
	{
		return std::string();
	}

	return "mouse state xdrag test failed\n";
}
