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

	for (int i{ 0 }; i < (int)windowsPlatform::MouseButtons::size; i++)
	{
		unit.press((windowsPlatform::MouseButtons)i);
		unit.release((windowsPlatform::MouseButtons)i);

		successes += unit.getButton((windowsPlatform::MouseButtons)i) == false;
	}

	if (successes == (int)windowsPlatform::MouseButtons::size)
	{
		return std::string();
	}

	return "mouse buttons release test failed\n";
}
