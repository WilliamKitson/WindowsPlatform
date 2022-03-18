#include "MouseWheelTester.h"

MouseWheelTester::MouseWheelTester()
{
}

MouseWheelTester::~MouseWheelTester()
{
}

std::string MouseWheelTester::test()
{
	std::string failures{ "" };

	failures += testPress();
	failures += testReset();

	return failures;
}

std::string MouseWheelTester::testPress()
{
	return MouseWheelPressTest().test();
}

std::string MouseWheelTester::testReset()
{
	return MouseWheelResetTest().test();
}
