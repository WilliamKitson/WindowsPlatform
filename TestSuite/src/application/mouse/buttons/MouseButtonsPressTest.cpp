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

	for (int i{ 0 }; i < (int)windowsPlatform::MouseButtons::size; i++)
	{
		unit.press((windowsPlatform::MouseButtons)i);
		successes += unit.getButton((windowsPlatform::MouseButtons)i) == true;
	}

	if (successes == (int)windowsPlatform::MouseButtons::size)
	{
		return std::string();
	}

	return "mouse buttons press test failed\n";
}
