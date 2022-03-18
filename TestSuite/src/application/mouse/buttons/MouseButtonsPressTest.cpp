#include "MouseButtonsPressTest.h"

MouseButtonsPressTest::MouseButtonsPressTest()
	: successes{ 0 }
{
}

MouseButtonsPressTest::~MouseButtonsPressTest()
{
}

std::string MouseButtonsPressTest::test()
{
	WindowsPlatform::Mouse unit;

	for (int i{ 0 }; i < (int)WindowsPlatform::MouseButtons::size; i++)
	{
		unit.press((WindowsPlatform::MouseButtons)i);
		successes += unit.getButton((WindowsPlatform::MouseButtons)i) == true;
	}

	if (successes == (int)WindowsPlatform::MouseButtons::size)
	{
		return std::string();
	}

	return "mouse buttons press test failed\n";
}
