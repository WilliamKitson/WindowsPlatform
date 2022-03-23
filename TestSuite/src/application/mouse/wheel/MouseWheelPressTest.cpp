#include "MouseWheelPressTest.h"

MouseWheelPressTest::MouseWheelPressTest()
	: successes{ 0 }
{
}

MouseWheelPressTest::~MouseWheelPressTest()
{
}

std::string MouseWheelPressTest::test()
{
	windowsPlatform::Mouse unit;

	unit.wheel(MAKEWPARAM(0, WHEEL_DELTA * 1));
	successes += unit.getButton(windowsPlatform::MouseButtons::mouse_scrollForwards) == true;

	unit.wheel(MAKEWPARAM(0, WHEEL_DELTA * -1));
	successes += unit.getButton(windowsPlatform::MouseButtons::mouse_scrollBackwards) == true;

	if (successes == 2)
	{
		return std::string();
	}

	return "mouse wheel press test failed\n";
}
