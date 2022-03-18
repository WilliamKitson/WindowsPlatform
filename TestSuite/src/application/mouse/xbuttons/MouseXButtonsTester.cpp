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

	return failures;
}

std::string MouseXButtonsTester::testPress()
{
	return MouseXButtonsPressTest().test();
}
