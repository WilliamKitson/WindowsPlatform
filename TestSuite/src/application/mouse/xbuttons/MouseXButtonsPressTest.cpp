#include "MouseXButtonsPressTest.h"

MouseXButtonsPressTest::MouseXButtonsPressTest()
	: successes{ 0 }
{
}

MouseXButtonsPressTest::~MouseXButtonsPressTest()
{
}

std::string MouseXButtonsPressTest::test()
{
	WindowsPlatform::Mouse unit;

	unit.press((WPARAM)65536);
	successes += unit.getButton(WindowsPlatform::MouseButtons::mouse_MB4) == true;

	unit.press((WPARAM)131072);
	successes += unit.getButton(WindowsPlatform::MouseButtons::mouse_MB5) == true;

	if (successes == 2)
	{
		return std::string();
	}

	return "mouse XButton press test failed\n";
}
