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
	windowsPlatform::Mouse unit;

	for (int i{ 0 }; i < (int)windowsPlatform::Buttons::size; i++)
	{
		unit.press((windowsPlatform::Buttons)i);
		successes += unit.getButton((windowsPlatform::Buttons)i) == true;
	}

	if (successes == (int)windowsPlatform::Buttons::size)
	{
		return std::string();
	}

	return "mouse buttons press test failed\n";
}
