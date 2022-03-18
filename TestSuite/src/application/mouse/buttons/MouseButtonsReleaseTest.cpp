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
	WindowsPlatform::Mouse unit;

	for (int i{ 0 }; i < (int)WindowsPlatform::MouseButtons::size; i++)
	{
		unit.press((WindowsPlatform::MouseButtons)i);
		unit.release((WindowsPlatform::MouseButtons)i);

		successes += unit.getButton((WindowsPlatform::MouseButtons)i) == false;
	}

	if (successes == (int)WindowsPlatform::MouseButtons::size)
	{
		return std::string();
	}

	return "mouse buttons release test failed\n";
}
