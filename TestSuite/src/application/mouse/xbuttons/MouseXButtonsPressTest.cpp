#include "MouseXButtonsPressTest.h"

MouseXButtonsPressTest::MouseXButtonsPressTest()
{
}

MouseXButtonsPressTest::~MouseXButtonsPressTest()
{
}

std::string MouseXButtonsPressTest::test()
{
	WindowsPlatform::Mouse unit;

	int successes{ 0 };

	unit.press(XBUTTON1);
	successes += unit.getButton(WindowsPlatform::MouseButtons::mouse_MB4) == true;

	unit.press(XBUTTON2);
	successes += unit.getButton(WindowsPlatform::MouseButtons::mouse_MB5) == true;

	if (successes == 2)
	{
		return std::string();
	}

	return "mouse XButton press test failed\n";
}
