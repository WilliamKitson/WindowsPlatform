#include "MouseWheelResetTest.h"

MouseWheelResetTest::MouseWheelResetTest()
	: successes{ 0 }
{
}

MouseWheelResetTest::~MouseWheelResetTest()
{
}

std::string MouseWheelResetTest::test()
{
	WindowsPlatform::Mouse unit;

	unit.wheel(MAKEWPARAM(0, WHEEL_DELTA * 1));
	unit.reset();
	successes += unit.getButton(WindowsPlatform::MouseButtons::mouse_scrollForwards) == false;

	unit.wheel(MAKEWPARAM(0, WHEEL_DELTA * -1));
	unit.reset();
	successes += unit.getButton(WindowsPlatform::MouseButtons::mouse_scrollBackwards) == false;

	if (successes == 2)
	{
		return std::string();
	}

	return "mouse wheel reset test failed\n";
}
