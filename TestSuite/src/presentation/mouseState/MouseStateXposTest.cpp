#include "MouseStateXposTest.h"

MouseStateXposTest::MouseStateXposTest()
{
}

MouseStateXposTest::~MouseStateXposTest()
{
}

std::string MouseStateXposTest::test()
{
	MouseState unit{
		1,
		0,
		0.0f,
		0.0f
	};

	if ((unit == MouseState()) == false)
	{
		return std::string();
	}

	return "mouse state xpos test failed\n";
}
