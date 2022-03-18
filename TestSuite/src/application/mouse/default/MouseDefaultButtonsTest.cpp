#include "MouseDefaultButtonsTest.h"

MouseDefaultButtonsTest::MouseDefaultButtonsTest()
	: successes{ 0 }
{
}

MouseDefaultButtonsTest::~MouseDefaultButtonsTest()
{
}

std::string MouseDefaultButtonsTest::test()
{
	WindowsPlatform::Mouse unit;

	for (int i{ 0 }; i < (int)WindowsPlatform::MouseButtons::size; i++)
	{
		successes += unit.getButton((WindowsPlatform::MouseButtons)i) == false;
	}

	if (successes == (int)WindowsPlatform::MouseButtons::size)
	{
		return std::string();
	}

	return "mouse default buttons test failed\n";
}
