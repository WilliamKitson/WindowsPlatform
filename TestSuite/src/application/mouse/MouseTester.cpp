#include "MouseTester.h"

MouseTester::MouseTester()
{
}

MouseTester::~MouseTester()
{
}

std::string MouseTester::test()
{
	std::string failures{ "" };

	failures += testDefault();

	return failures;
}

std::string MouseTester::testDefault()
{
	return MouseDefaultTester().test();
}
