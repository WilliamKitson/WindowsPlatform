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
	WindowsPlatform::Mouse unit;

	unit.press(XBUTTON1);
	unit.release(XBUTTON1);
	successes += unit.getButton(WindowsPlatform::MouseButtons::mouse_MB4) == false;

	unit.press(XBUTTON2);
	unit.release(XBUTTON2);
	successes += unit.getButton(WindowsPlatform::MouseButtons::mouse_MB5) == false;

	if (successes == 2)
	{
		return std::string();
	}

	return "mouse XButtons release test failed\n";
}
