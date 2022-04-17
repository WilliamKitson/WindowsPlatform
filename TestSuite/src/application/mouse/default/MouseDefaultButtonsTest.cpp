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
	windowsPlatform::Mouse unit;

	for (int i{ 0 }; i < (int)windowsPlatform::Buttons::size; i++)
	{
		successes += unit.getButton((windowsPlatform::Buttons)i) == false;
	}

	if (successes == (int)windowsPlatform::Buttons::size)
	{
		return std::string();
	}

	return "mouse default buttons test failed\n";
}
