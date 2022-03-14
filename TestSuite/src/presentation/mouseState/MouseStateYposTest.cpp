#include "MouseStateYposTest.h"

MouseStateYposTest::MouseStateYposTest()
{
}

MouseStateYposTest::~MouseStateYposTest()
{
}

std::string MouseStateYposTest::test()
{
	WindowsPlatform::MouseState unit{
		0,
		1,
		0.0f,
		0.0f
	};

	if ((unit == WindowsPlatform::MouseState()) == false)
	{
		return std::string();
	}

	return "mouse state ypos test failed\n";
}
