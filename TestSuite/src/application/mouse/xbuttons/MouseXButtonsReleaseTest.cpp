#include "MouseXButtonsReleaseTest.h"

MouseXButtonsReleaseTest::MouseXButtonsReleaseTest()
	: successes{ 0 }
{
}

MouseXButtonsReleaseTest::~MouseXButtonsReleaseTest()
{
}

std::string MouseXButtonsReleaseTest::test()
{
	windowsPlatform::Mouse unit;

	unit.press((WPARAM)65536);
	unit.release((WPARAM)65536);
	successes += unit.getButton(windowsPlatform::Buttons::mouse_MB4) == false;

	unit.press((WPARAM)131072);
	unit.release((WPARAM)131072);
	successes += unit.getButton(windowsPlatform::Buttons::mouse_MB5) == false;

	if (successes == 2)
	{
		return std::string();
	}

	return "mouse XButtons release test failed\n";
}
