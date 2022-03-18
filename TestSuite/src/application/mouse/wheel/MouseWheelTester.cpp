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

	return failures;
}

std::string MouseWheelTester::testPress()
{
	return MouseWheelPressTest().test();
}
