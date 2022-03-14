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
	failures += testXpos();

	return failures;
}

std::string MouseStateTester::testDefault()
{
	return MouseStateDefaultTest().test();
}

std::string MouseStateTester::testXpos()
{
	return MouseStateXposTest().test();
}
