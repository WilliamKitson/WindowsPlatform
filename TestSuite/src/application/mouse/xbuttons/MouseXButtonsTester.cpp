#include "MouseXButtonsTester.h"

MouseXButtonsTester::MouseXButtonsTester()
{
}

MouseXButtonsTester::~MouseXButtonsTester()
{
}

std::string MouseXButtonsTester::test()
{
	std::string failures{ "" };

	failures += testPress();
	failures += testRelease();

	return failures;
}

std::string MouseXButtonsTester::testPress()
{
	return MouseXButtonsPressTest().test();
}

std::string MouseXButtonsTester::testRelease()
{
	return MouseXButtonsReleaseTest().test();
}
