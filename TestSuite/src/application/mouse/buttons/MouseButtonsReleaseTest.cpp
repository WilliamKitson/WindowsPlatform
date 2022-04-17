#include "MouseButtonsReleaseTest.h"

MouseButtonsReleaseTest::MouseButtonsReleaseTest()
	: successes{ 0 }
{
}

MouseButtonsReleaseTest::~MouseButtonsReleaseTest()
{
}

std::string MouseButtonsReleaseTest::test()
{
	windowsPlatform::Mouse unit;

	for (int i{ 0 }; i < (int)windowsPlatform::Buttons::size; i++)
	{
		unit.press((windowsPlatform::Buttons)i);
		unit.release((windowsPlatform::Buttons)i);

		successes += unit.getButton((windowsPlatform::Buttons)i) == false;
	}

	if (successes == (int)windowsPlatform::Buttons::size)
	{
		return std::string();
	}

	return "mouse buttons release test failed\n";
}
