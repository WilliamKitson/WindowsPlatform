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

	return failures;
}

std::string MouseButtonsTester::testPress()
{
	return MouseButtonsPressTest().test();
}
