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
	failures += testYpos();
	failures += testXdrag();
	failures += testYdrag();

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

std::string MouseStateTester::testYpos()
{
	return MouseStateYposTest().test();
}

std::string MouseStateTester::testXdrag()
{
	return MouseStateXdragTest().test();
}

std::string MouseStateTester::testYdrag()
{
	return MouseStateYdragTest().test();
}
