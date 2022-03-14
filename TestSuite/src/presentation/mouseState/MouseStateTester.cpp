#include "MouseStateTester.h"

MouseStateTester::MouseStateTester()
{
}

MouseStateTester::~MouseStateTester()
{
}

std::string MouseStateTester::test()
{
	std::string failures{ "" };

	failures += testDefault();

	return failures;
}

std::string MouseStateTester::testDefault()
{
	return MouseStateDefaultTest().test();
}
