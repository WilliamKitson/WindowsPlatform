#include "MouseButtonsTester.h"

MouseButtonsTester::MouseButtonsTester()
{
}

MouseButtonsTester::~MouseButtonsTester()
{
}

std::string MouseButtonsTester::test()
{
	std::string failures{ "" };

	failures += testPress();
	failures += testRelease();

	return failures;
}

std::string MouseButtonsTester::testPress()
{
	return MouseButtonsPressTest().test();
}

std::string MouseButtonsTester::testRelease()
{
	return MouseButtonsReleaseTest().test();
}
